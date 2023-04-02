program compet;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n, i:integer;

begin
  assign (input,'wonder.in');
  assign (output,'wonder.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to (n-2) do write('1 ');
  write ('2 ');
  write (n);
  close(input);
  close(output);
end.
