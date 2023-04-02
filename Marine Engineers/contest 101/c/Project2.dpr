program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var i : integer;
begin
 assign (output,'telefon.in');
 rewrite(output);
 for i:=25000 downto 1 do writeln (i);

 close(output);

end.
 