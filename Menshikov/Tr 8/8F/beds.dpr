program beds;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const max = 200;

type
 location = record
  x, y : integer;
  end;

var i, j : integer;
    n, m : integer;
    u : location;
    a : array [1..max, 1..max] of char;
    color : array [1..max, 1..max] of char;
    dx : array [1..4] of integer = (0,0,1,-1);
    dy: array [1..4] of integer = (1,-1,0,0);
    bed : integer;

procedure dfs (u : location);
var i : integer;
    v : location;

begin
 color [u.y,u.x] := 'g';
 for i:=1 to 4 do
 begin
  v.x:=u.x+dx[i];
  v.y:=u.y+dy[i];
  if (v.y<=n) and (v.y>0)and(v.x<=m)and(v.x>0)
   and (a[v.y,v.x]='#') and (color[v.y,v.x]='w')
    then dfs(v);
 end;
end;


begin
 assign (input,'beds.in');
 reset (input);
 assign (output,'beds.out');
 rewrite(output);

 readln (n, m);
 for i:=1 to n do
 begin
  for j:=1 to m do
  begin
   read (a[i,j]);
   color [i,j]:='w';
  end;
  readln;
 end;

 for i:=1 to n do
  for j:=1 to m do
   if (a[i,j]='#') and (color[i,j]='w') then
   begin
    u.x:=j;
    u.y:=i;
    inc (bed);
    dfs (u);
   end;
 
 writeln (bed);
 close (input);
 close (output);
end.



