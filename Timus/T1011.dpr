program T1011;
{$apptype console}

uses
  sysutils;

var p, l, r, q : extended;
    n : integer;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1011.in');
 reset(input);
 assign(output, 'T1011.out');
 rewrite(output);
{$ENDIF}

 read (p);
 read (q);
 n:=1;
 while n<=10000 do
 begin
  l:=p*n/100;
  r:=q*n/100;
  if (r>(trunc(r))) and (l<trunc(r)) then
  begin
   write (n);
   break;
  end;
  inc(n);
 end;



{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
