program T1149;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n : integer;

procedure A (n : integer);
var i : integer;

begin
 for i:=1 to n do
 begin
  write ('sin(',i);
  if (odd(i)) and (i<>n) then write ('-')
   else if (i<>n) then write ('+');
 end;
 for i:=1 to n do write (')');
end;

procedure S (n : integer);
var i : integer;

begin
 for i:=1 to n-1 do write ('(');
 for i:=1 to n do
 begin
  A (i);
  if i <>n then write ('+', n-i+1, ')') else write ('+', 1);
 end;
end;

begin
 assign (input,'T1149.in');
 reset (input);
 assign (output,'T1149.out');
 rewrite(output);

 readln (n);
 S (n);
 
 close (input);
 close (output);
end.



