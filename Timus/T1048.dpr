program T1048;
{$apptype console}

uses
  sysutils;

var a, b : array [1..1000000] of byte;
    len, i : integer;

procedure add;
var i, carry : integer;

begin
 carry:=0;
 for i:=len downto 1 do
 begin
  a[i]:=a[i]+b[i]+carry;
  carry:=a[i] div 10;
  a[i]:=a[i] mod 10;
 end;
end;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1048.in');
 reset(input);
 assign(output, 'T1048.out');
 rewrite(output);
{$ENDIF}

 fillchar(a,1000000,0);
 readln (len);

 for i:=1 to len do
  readln (a[i], b[i]);

 add; 

 for i:=1 to len do
  write (a[i]);


{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
