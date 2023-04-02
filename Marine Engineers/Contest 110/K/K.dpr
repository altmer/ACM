program D2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a, b: array [1..101,1..101] of integer;
    dx : array [1..4] of integer = (1,  1, -1, -1);
    dy : array [1..4] of integer = (1, -1,  1, -1);
    color, color2 : array [1..101, 1..101] of boolean;
    res : boolean;
    start,n,ans,test,cur,i,j: integer;



procedure dfs1 (i,j : integer);
var v : integer;
    di, dj , k: integer;

begin
 i:=1;
 j:=1;
 if (i=n) and (j=n) then res:=true;
 color [i, j]:=true;
 for k:=1 to 4 do
 begin
  di:=i+dx[i];
  dj:=j+dy[i];

  if (di>0) and (di<=n) and (dj>0) and (dj<=n) and (a[di,dj]<=0)
  then
  begin
   dfs1 (di, dj);
  end;
 end;
end;

procedure dfs2 (i,j : integer);
var v : integer;
    di, dj , k: integer;

begin

 if (i=n) and (j=n) then res:=true;
 color [i, j]:=true;
 for k:=1 to 4 do
 begin
  di:=i+dx[i];
  dj:=j+dy[i];

  if (di>0) and (di<=n) and (dj>0) and (dj<=n) and (b[di,dj]>=0)
  then
  begin
   dfs2 (di, dj);
  end;
 end;
end;




procedure up;
var floor, i, j, t : integer;

begin
  t:=-1;
 while not res do
 begin
  inc(t);
  for i:=1 to n do
  for j:=1 to n do
   a[i,j]:=a[i,j]-(start+t);
  dfs1 (1,1);
  color:=color2;
  for i:=1 to n do
  for j:=1 to n do
   b[i,j]:=b[i,j]-(start-t);
  dfs2(1,1);
 end;
 ans:=t-start
end;







begin
 assign (input,'honeymoon.in');
 assign (output,'honeymoon.out');
 reset(input);
 rewrite(output);

 readln (test);

 for cur:=1 to test do
 begin
  readln (n);
  for i:=1 to n do
  begin
   for j:=1 to n do read (a[i,j]);
   readln;
  end;


  b:=a;
  start:=a[1,1];
  up;
  writeln('Scenario #',cur,':');
  writeln(ans);





 end;


 close(input);
 close(output);
end.
