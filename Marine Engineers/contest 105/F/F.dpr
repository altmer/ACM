program F;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a : array [1..50] of int64;
    i, n, k, t : integer;


procedure

begin
 assign (input,'f.in');
 assign (output,'f.out');
 reset(input);
 rewrite(output);

 read (n);
 for i:=1 to n do
  read (a[i]);
 read (k);

 for i:=1 to k do
  for j:=1 to
 
 close(input);
 close(output);
end.
