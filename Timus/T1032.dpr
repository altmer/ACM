program T1032;
{$apptype console}

uses
  sysutils;

var n, i, j, k : integer;
    a, s : array [0..10000] of integer;
    res : boolean;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1032.in');
 reset(input);
 assign(output, 'T1032.out');
 rewrite(output);
{$ENDIF}

 readln (n);

 for i:=1 to n do
 begin
  readln (a[i]);
  s[i]:=(s[i-1]+a[i]) mod n;
  if s[i]=0 then
  begin
   writeln (i);
   for j:=1 to i do
    writeln (a[j]);
   res:=true;
   break;
  end;
 end;

 if not res then
 begin
  for i:=1 to n-1 do
  begin
   for j:=i+1 to n do
   begin
    if s[i]=s[j] then
    begin
     writeln (j-i);
     for k:=i+1 to j do
      writeln (a[k]);
     res:=true;
     break
    end;
   end;
   if res then break;
  end;
 end;

 if not res then writeln (0);
{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
