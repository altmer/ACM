program honeymoon;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const maxn=100;

var a : array [0..maxn+1,0..maxn+1] of integer;
    color : array [0..maxn+1, 0..maxn+1] of boolean;
    dx : array [1..4] of integer = (1,-1,0,0);
    dy : array [1..4] of integer = (0,0,1,-1);
    cur, test, n, minv, maxv, low, high, i,j, limit, d : integer;
    found : boolean;


procedure dfs (x, y : integer);
var x2, y2, i : integer;

begin
 color [x,y]:=true;
 for i:=1 to 4 do
 begin
  x2:=x+dx[i];
  y2:=y+dy[i];
  if (a[x2, y2]>=low) and (a[x2,y2]<=high) and (not color[x2,y2]) then
   dfs (x2, y2);
 end;
end;


begin
 assign (input,'Honeymoon.in');
 assign (output,'Honeymoon.out');
 reset(input);
 rewrite(output);

 readln (test);
 for cur:=1 to test do
 begin
  readln (n);
  found:=false;
  for i:=1 to n do
  begin
   color[i,0]:=true;
   color[0,i]:=true;
   color[n+1,i]:=true;
   color[i,n+1]:=true;
   for j:=1 to n do read (a[i,j]);
   readln;
  end;

  if a[1,1]>a[n,n] then
  begin
   minv:=a[n,n];
   maxv:=a[1,1];
  end
  else
  begin
   minv:=a[1,1];
   maxv:=a[n,n];
  end;

  d:=maxv-minv;
  while not found do
  begin
   if minv<200-d then limit:=minv else limit:=200-d;
   if maxv-d>0 then low:=maxv-d else low:=0;
   for low:=low to limit do
   begin
    high:=low+d;
    for i:=1 to n do
    for j:=1 to n do color[i,j]:=false;
    dfs (1,1);
    if color[n,n] then
    begin
     writeln ('Scenario #', cur, ':');
     writeln (d);
     writeln;
     found:=true;
     break;
    end;
   end;
   inc(d);
  end;

 end;
 close(input);
 close(output);
end.
