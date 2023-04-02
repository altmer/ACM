program T1194;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n, k : integer;

begin
 assign (input,'T1194.in');
 reset (input);
 assign (output,'T1194.out');
 rewrite(output);

 readln (n, k);
 writeln ((n*(n-1)-2*k)/2 : 0: 0);

 close (input);
 close (output);
end.



