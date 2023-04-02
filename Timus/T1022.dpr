program T1022;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const max = 100;

type
 final = record
  vortex, t : integer;
  end;

var i, j : integer;
    n : integer;
    k : integer = -1;
    fin : boolean = false;
    time : integer;
    a : array [1..max, 1..max] of byte;
    color : array [1..max] of char;
    f : array [0..max-1] of final;

procedure qs (var a : array of final; l, r : integer);
var
 i, j : integer;
 mid, t : final;

begin
 i:=l;
 j:=r;
 mid:=a[(i+j)div 2];
 repeat
  while a[i].t > mid.t do inc (i);
  while a[j].t < mid.t do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc(i);
   dec(j);
  end;
 until i>j;
 if l<j then qs (a,l,j);
 if r>i then qs (a,i,r);
end;

procedure dfs (u : integer);
var v : integer;

begin
 color [u] := 'g';
 inc (time);
 for v:=1 to n do
  if  a[u,v] = 1 then
   if color[v]='w' then dfs (v);
 inc(time);
 f[u-1].t:=time;
end;


begin
 assign (input,'T1022.in');
 reset (input);
 assign (output,'T1022.out');
 rewrite(output);


 readln (n);
 for i:=1 to n do
 begin
   while not fin do
   begin
    read (k);
    if k>0 then
    begin
     a[i,k] := 1;
     fin:=false;
    end
    else fin:=true;
   end;
  fin:=false;
  readln;
  color[i]:='w';
  f[i-1].t:=0;
  f[i-1].vortex:=i;
 end;

 for i:=1 to n do
  if color[i]='w' then dfs(i);

 qs (f, 0, n-1);

 for i:=0 to n-1 do
  write (f[i].vortex, ' ');
 
 close (input);
 close (output);
end.



