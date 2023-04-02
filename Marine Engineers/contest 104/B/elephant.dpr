program elephant;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s : string;

begin
 assign (input,'checkers.in');
 assign (output,'checkers.out');
 reset(input);
 rewrite(output);
 readln (s);
 writeln (s);

 close(input);
 close(output);
end.
