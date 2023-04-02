program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i : integer;  

begin
  assign (output, 'shopaholic.in');
  rewrite (output);
  randomize;
  for i:=1 to 20000 do write (random (200000), ' ');
  close (output);
end.
