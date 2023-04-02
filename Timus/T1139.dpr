program T1139;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var m, n, i, gcd : integer;

function min (a, b : integer) : integer;

begin
 if a<b then min:=a else min:=b;
end;

begin
 assign (input,'T1139.in');
 reset (input);
 assign (output,'T1139.out');
 rewrite(output);

 readln (m, n);
 dec(m); dec(n);

 for i:=1 to min(m,n) do
  if (m mod i = 0) and (n mod i = 0) then
   gcd:=i;
 writeln (m+n-gcd);  

 close (input);
 close (output);
end.



