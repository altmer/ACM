program constell;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const max = 1000;

var n, m : integer;
    k, l : integer;
    i : integer;
    time : integer;
    a : array [1..max, 1..max] of byte;
    color : array [1..max] of char;
    n_res : boolean;
    ans : integer;

procedure dfs (u : integer; var n_res : boolean);
var v : integer;
    t : integer;

begin
 color [u] := 'g';
 inc (time);
 t:=time;
 for v:=1 to n do
  if  a[u,v] = 1 then
   if color[v]='w' then dfs (v, n_res);
 if time = t then n_res:=true else n_res:=false;
end;

begin
 assign (input,'constell.in');
 reset (input);
 assign (output,'constell.out');
 rewrite(output);

 readln (n, m);
 for i:=1 to m do
 begin
  read (k, l);
  a[k,l]:=1;
  a[l,k]:=1;
 end;

 for i:=1 to n do color[i]:='w';

 for i:=1 to n do
  if color[i]='w' then
  begin
   dfs (i, n_res);
   if n_res=false then inc (ans);
  end;
  writeln (ans);
 close (input);
 close (output);
end.



