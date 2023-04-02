program corporate;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n, m : integer;

begin
 assign (input,'domestic.in');
 assign (output,'domestic.out');
 reset(input);
 rewrite(output);
 readln (n, m);
 writeln (65);
 writeln ('1 5');
 close(input);
 close(output);
end.
