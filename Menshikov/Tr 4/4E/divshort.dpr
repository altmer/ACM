program divsho;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const max = 60040;

type number = array [1..max] of integer;

var a : number;
    divisor, rem, i : integer;
    s : string;

procedure divshort (var n : number; divisor : integer; var rem : integer);
var i : integer;

begin
 rem:=0;
 for i:=max downto max-length(s)+1 do
 begin
  rem:=rem*10+n[i];
  n[i]:=rem div divisor;
  rem:=rem mod divisor;
 end;
end;

begin
 assign (input,'divshort.in');
 reset (input);
 assign (output,'divshort.out');
 rewrite(output);

 readln (s);
 for i:=1 to length(s) do
  a[max-i+1]:=ord(s[i])-ord('0');

 readln (divisor);
 divshort (a, divisor, rem);

 i:=max;
 while a[i]=0 do dec (i);

 for i:=i downto max-length(s)+1 do write (a[i]);
 writeln;
 writeln(rem);

 close (input);
 close (output);
end.



