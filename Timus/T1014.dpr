program T1014;
{$apptype console}

uses
  sysutils;

type mas = array [0..100] of integer;

var divis : array [2..9] of integer;
    a, ans : mas;
    i, j, prod, cur, n : integer;
    res : boolean;

procedure permut (var a : mas; k : integer);
var i, prod : integer;

begin
 prod:=1;
 for i:=1 to a[0] do
  prod:=prod*a[i];

 if prod=n then
 begin
  if a[0]<ans[0] then ans:=a
  else if a[0]=ans[0] then
   for i:=1 to a[0] do
    if a[i]<ans[i] then ans:=a
     else if ans[i]<a[i] then break; 
 end
 else if prod>n then exit

 else
 begin
  for i:=2 to 9 do
   if divis[i]<>0 then
   begin
    inc(a[0]);
    dec (divis[i]);
    a[k]:=i;
    permut (a, k+1);
    dec (a[0]);
    inc (divis[i]);
    a[k]:=0;
   end;
 end;
end;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1014.in');
 reset(input);
 assign(output, 'T1014.out');
 rewrite(output);
{$ENDIF}

 readln (n);
 ans[0]:=1000;
 if n=0 then
 begin
  writeln (10);
  res:=true;
 end
 else
 if n<10 then
 begin
  write (n);
  res:=true;
 end
 else
 for i:=2 to 9 do
  if n mod i = 0 then
  begin
   divis[i]:=0;
   cur:=n;
   while cur mod i = 0 do
   begin
    cur:=cur div i;
    inc(divis[i]);        
   end;      
  end;

 prod:=1;

 for i:=2 to 9 do
  for j:=1 to divis[i] do
   prod:=prod*i;

 a[0]:=0;
 if not res then
 if prod<n then
 begin
  writeln ('-1');
  res:=true;
 end

 else
  permut (a, 1);

 if not res then
  if ans[0]=1000 then writeln ('-1')else
   for i:=1 to ans[0] do
    write (ans[i]);


{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
