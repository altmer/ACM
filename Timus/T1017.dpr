program T1017;
{$apptype console}

uses
  sysutils;

var n, i, j : integer;
    a : array [0..500] of extended;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1017.in');
 reset(input);
 assign(output, 'T1017.out');
 rewrite(output);
{$ENDIF}

 read(n);
 fillchar(a,sizeof(a),0); a[0]:=1;
 for j:=1 to n do
 for i:=n downto j do a[i]:=a[i]+a[i-j];
 a[n]:=a[n]-1;
 writeLn(a[n]:0:0);

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
