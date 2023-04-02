program T1247;
{$apptype console}

uses
  sysutils;

var s, n, i : integer;
    a : array [1..30000] of integer;
    sum : int64;
    res : boolean;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1247.in');
 reset(input);
 assign(output, 'T1247.out');
 rewrite(output);
{$ENDIF}
 readln (s, n);
 sum:=0;
 for i:=1 to s do
 begin
  readln (a[i]);
  sum:=sum+a[i];
  if sum>n+i then
  begin;
   res:=true;
   break;
  end;
 end;
 if not res then
 begin
 sum:=0;
 for i:=s downto 1 do
 begin
  sum:=sum+a[i];
  if sum>s-i+1+n then
  begin
   res:=true;
   break;
  end;
 end;
 end;

 if res then writeln ('NO') else writeln ('YES');

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
