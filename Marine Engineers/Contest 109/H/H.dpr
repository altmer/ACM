program A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n : integer;

begin
 assign (input,'H.in');
 assign (output,'H.out');
 reset(input);
 rewrite(output);

 readln (n);
 

 close(input);
 close(output);
end.
