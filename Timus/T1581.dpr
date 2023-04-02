program T1581;
{$apptype console}

uses
  sysutils;

var a : array [1..1000] of integer;
    i, n, k : integer;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1581.in');
 reset(input);
 assign(output, 'T1581.out');
 rewrite(output);
{$ENDIF}

 readln(n);
 for i:=1 to n do
  read (a[i]);

 i:=1; 
 while i<=n do
 begin
  k:=1;
  while a[i+1]=a[i] do
  begin
   inc(i);
   inc(k);
  end;
  write (k, ' ', a[i], ' ');
  inc(i);
 end; 

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
