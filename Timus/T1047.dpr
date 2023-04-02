program T1047;
{$apptype console}

uses
  sysutils;


var a, c : array [0..3001] of extended;
    n, i, k : integer;
    
begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1047.in');
 reset(input);
 assign(output, 'T1047.out');
 rewrite(output);
{$ENDIF}

 readln (n);
 readln(a[0]);
 readln (a[n+1]);
 for i:=1 to n do readln (c[i]);

 for k:=n downto 1 do
 begin
  a[k]:=a[0];
  for i:=k downto 1 do
   a[k]:=a[k]-2*i*c[i];
  a[k]:=a[k]+k*a[k+1];
  a[k]:=a[k]/(k+1);
 end;

 writeln (a[1] : 0 :2);

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
