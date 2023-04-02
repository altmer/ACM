program route2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var a, M : array [0..101, 0..101] of integer;
    n, k, i, j : integer;
    rmax : integer = 0;

function max (a, b, c, d : integer) : integer;

begin
 if a>b then
 begin
  if a>c then
  begin
   if a>d then max:=a else max:=d;
  end

  else
  begin
   if c>d then max:=c else max:=d;
  end;
 end

 else
 begin
  if b>c then
  begin
   if b>d then max:=b else max:=d;
  end

  else
  begin
   if c>d then max:=c else max:=d;
  end;
 end;
end;    

procedure sum (k : integer);
var i, j : integer;

begin
 for i:=1 to n do
  for j:=1 to n do
   if odd (i+j)<>odd (k) then
    if max (m[i-1, j], m[i+1, j], m[i, j-1], m[i, j+1])<>0 then
     m[i, j]:=max (m[i-1, j], m[i+1, j], m[i, j-1], m[i, j+1])+a[i,j];
end;

procedure set0 (k : integer);
var i, j : integer;

begin
 for i:=1 to n do
  for j:=1 to n do
   if odd(i+j)=odd(k) then
    m[i, j] := 0; 
end;

begin
 assign(input,'route2.in');
 reset (input);
 assign(output,'route2.out');
 rewrite(output);

 readln (n, k);

 for i:=1 to n do
 begin
  for j:=1 to n do read (a[i,j]);
  readln;
 end;

 m[1, 1]:=a[1,1];
 for i:=2 to k do
 begin
  sum (i);
  set0 (i);
 end;

 for i:=1 to n do
  for j:=1 to n do
   if m[i,j]>rmax then rmax:=m[i,j];

 writeln (rmax);
 
 close(input);
 close(output);
end.
