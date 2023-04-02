program I;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a : array [1..50] of int64;
    i, n, k, t : integer;


procedure

begin
 assign (input,'I.in');
 assign (output,'I.out');
 reset(input);
 rewrite(output);


 
 close(input);
 close(output);
end.
