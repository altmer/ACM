program T1079;
{$apptype console}

uses
  sysutils;

var a : array [0..100000] of integer;
    i, n, max : integer;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1079.in');
 reset(input);
 assign(output, 'T1079.out');
 rewrite(output);
{$ENDIF}

 a[0]:=0;
 a[1]:=1; 
 for i:=2 to 100000 do
 begin
  if i mod 2=0 then
   a[i]:=a[i div 2]
    else a[i]:=a[i div 2] + a[(i div 2) +1];
 end;  

 repeat
  readln (n);
  max:=0;
  for i:=1 to n do
   if a[i]>max then max:=a[i];
  if n<>0 then writeln (max);
 until n=0;

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
