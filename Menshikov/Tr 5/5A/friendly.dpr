program friendly;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var mas1 : array [1..25] of integer = (220, 1184, 2620, 5020, 6232, 10744, 12285,

begin
 assign(input,'friendly.in');
 reset (input);
 assign(output,'friendly.out');
 rewrite(output);



 close(input);
 close(output);
end.
