program T1073;
{$apptype console}

uses
  sysutils;

var a : array [1..60000] of integer;
    i, n, j : integer;
    res : integer = 60000;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1073.in');
 reset(input);
 assign(output, 'T1073.out');
 rewrite(output);
{$ENDIF}


 readln (n);

 a[1]:=1;
 a[2]:=2;
 a[3]:=3;
 for i:=4 to n do
 begin
  if frac (sqrt(i))=0 then a[i]:=1
   else
   begin
    a[i]:=60000;
    for j:=1 to trunc(sqrt(i)) do
     if a[i-j*j]+1 < a[i] then a[i]:=a[i-j*j]+1
   end;
 end;

 writeln (a[n]);

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
