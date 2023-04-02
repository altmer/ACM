program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var i : integer;
begin
  assign (output,'psycho.in');
  rewrite (output);
  randomize;
  for i:=1 to 50000 do writeln (random (100000){,' ', random (100000)});
  close (output);
end.
