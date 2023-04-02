program D;

{$APPTYPE CONSOLE}

{$M 1024, 5000000}

uses
  SysUtils;

const white = 0;
      grey = 1;
      black = 2;
      mine = 3;
      danger = 4;

var color : array [0..301, 0..301] of byte;
    dx : array [1..8] of integer = (1, 1, 1, 0, 0,  -1,  -1,  -1);
    dy : array [1..8] of integer = (-1,  0, 1,  1,  -1, -1,  0,  1  );
    k, l, i, j, n, m, test, cur : integer;
    x, y : integer;

procedure dfs (y, x : integer);
var i : byte;
    k, l : integer;

begin
 color [y, x]:=black;
 for i:=1 to 8 do
 begin
  l:=x+dx[i];
  k:=y+dy[i];
  if color[k, l]=white then dfs (k, l)
   else if color[k, l]=danger then color[k, l]:=grey;
 end;
end;

begin
 assign (input,'minemap.in');
 assign (output,'minemap.out');
 reset(input);
 rewrite(output);

 readln (test);
 for cur:=1 to test do
 begin
  for i:=1 to n do
   for j:=1 to n do
    color[i,j]:=white;

  readln (n);
  readln (m);

  for i:=0 to n+1 do
  begin
   color[0, i]:=black;
   color[i, 0]:=black;
   color[i, n+1]:=black;
   color[n+1,i]:=black;
  end;

  for i:=1 to m do
  begin
   readln (y, x);
   color[y,x]:=mine;
   for j:=1 to 8 do
   begin
    k:=y+dy[j];
    l:=x+dx[j];
    if color[k,l]=white then color[k,l]:=danger;
   end;
  end;

  x:=n div 2 + 1;
  y:=x;

  if color[y, x]=danger then color[y, x]:=grey
   else dfs (y, x);

  writeln ('Scenario #', cur, ':'); 
  for i:=1 to n do
  begin
   for j:=1 to n do
    case color[i,j] of

     white:  write ('?');
     danger: write ('?');
     mine:   write ('*');
     grey:   write ('#');
     black:  write ('.');
    end;
   writeln;
  end;
  writeln;
 end;

 close(input);
 close(output);
end.
