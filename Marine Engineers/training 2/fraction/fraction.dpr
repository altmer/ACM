program Project2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var k,n,i:integer;
    s: array [1..100] of string;
    a,b: string ;

begin
  assign(input,'fraction.in');
  reset (input);
  assign(output,'fraction.out');
  rewrite(output);
  readln(n);
for i:=1 to n do
readln(s[i]) ;

k:=pos('/', s[i]);
a:=copy(s[i], 0, k); {
b:=copy(s[i], (lenth(s[i])-k), k+1);
                      }

writeln(a);



  close(input);
  close(output);
end.
 