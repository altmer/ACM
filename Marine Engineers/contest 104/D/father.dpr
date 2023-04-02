program D;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const NL = 0;
      ML = 1;
      FarL = 2;

var n, i, j : integer;
    a : array [1..100000] of byte;
    answer : integer;

begin
 assign (input,'father.in');
 assign (output,'father.out');
 reset(input);
 rewrite(output);

 
 readln (n);
 for i:=2 to n do
 begin
  read (j);
  a[j]:=ML;
  if (a[i] = NL) and (j<>1) then a[i]:=FarL else a[i]:=ML; 
 end;
 for i:=2 to n do
  if a[i]=FarL then inc (answer);
 write (answer); 
 close(input);
 close(output);
end.
