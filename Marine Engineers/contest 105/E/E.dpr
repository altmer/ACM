program E;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a : array [1..20000, 1..20000] of integer;
    i, n, k, t : integer;

begin
 assign (input,'E.in');
 assign (output,'E.out');
 reset(input);
 rewrite(output);

 

 close(input);
 close(output);
end.
