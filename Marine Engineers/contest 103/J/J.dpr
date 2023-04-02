program J;
{$APPTYPE CONSOLE}

uses SysUtils;

const white = 0;
      grey = 1;
      black = 2;

var i, n, m, k, l : integer;
    a : array [1..100,1..100] of integer;
    color : array [1..100] of integer;
    fin : boolean;

procedure dfs (u : integer);
var v : integer;

begin
 color[u] := grey;
 for v:=1 to n do
  if (a[u,v] <> 0) and (color[v] = grey) then
  begin
   dec (a[u,v]);
   dec (a[v,u]);
   exit;
  end

  else if (a[u,v] <> 0) and (color[v] = white) then
  begin
   dec (a[u,v]);
   dec (a[v,u]);
   dfs (v);
   break;
  end

  else if (a[u,v] <> 0) and (color[v] = black) then
  begin
   writeln ('NO');
   halt;
  end;
 color[u]:=black;
end;

begin
 assign (input,'supertri.in');
 assign (output,'supertri.out');
 reset(input);
 rewrite(output);

 readln (n, m);
 for i:=1 to m do
 begin
  readln (k,l);
  inc(a[k,l]);
  inc(a[l,k]);
 end;

 for i:=1 to n do
  if color[i]<>black then dfs(i); 
 writeln('YES');

 close(input);
 close(output);
end.
