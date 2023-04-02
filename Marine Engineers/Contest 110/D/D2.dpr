program D2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var sc, nsc, n, m, i : integer;
    mas : array [1..2000, 1..2000] of boolean;
    color : array [1..2000] of boolean;
    gend : array [1..2000] of boolean;
    a, b, j : integer;
    res : boolean;

procedure dfs (u : integer);
var v: integer;

begin
 if not res then
 begin
 color[u]:=true;
 for v:=1 to n do
  if (mas[u,v]) and (not color[v]) then
  begin
   gend[v]:=not gend[u];
   dfs(v);
  end
  else if (mas[u,v]) and (color[v]) then
  begin
   if gend[v]=gend[u] then res:=true;
  end;
 end;
end;

begin
 assign (input,'bugs.in');
 assign (output,'bugs.out');
 reset(input);
 rewrite(output);

 readln (nsc);

 for sc:=1 to nsc do
 begin
  for i:=1 to n do
  for j:=1 to n do mas[i,j]:=false;

  for i:=1 to n do
  begin
   color[i]:=false;
   gend[i]:=false;
  end;
  readln (n, m);
  res:=false;


  for i:=1 to m do
  begin
   readln (a, b);
   mas[a,b]:=true;
   mas[b,a]:=true;
  end;

  for i:=1 to n do
   if not color[i] then
    dfs(i);
  
  writeln ('Scenario #', sc, ':');
  if res then writeln ('Suspicious bugs found!') else writeln ('No suspicious bugs found!');
  writeln;  
 end;
 close(input);
 close(output);
end.
