program four;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var st : array [0..20] of int64;
    i, n, m : integer;

begin
 assign (input,'four.in');
 assign (output,'four.out');
 reset(input);
 rewrite(output);

 readln (n, m);

 for i:=0 to n-1 do
  st[i]:=round(exp(i*ln(4)));

 for i:=0 to n-1 do
 begin




 end; 

 close(input);
 close(output);
end.
