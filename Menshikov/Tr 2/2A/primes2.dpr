program primes2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 i, j, m, n, k, num : integer;
 mas : array [1..1000000] of integer; 
 res : boolean;

begin
 assign (input,'primes2.in');
 reset (input);
 assign (output,'primes2.out');
 rewrite(output);
 readln (m, n);
 res := false;
 mas[1]:=1; mas[2]:=2; num:=2;

 for i:=3 to 1000000 do
  begin
   k:=0;
   for j:=2 to num do
   begin
    if (i mod mas[j] = 0) and (mas[j]<>i) then
    begin
     inc(k);
     break;
    end;
    if mas[j]>sqrt(i) then break;
   end;
   if k=0 then
   begin
    inc(num);
    mas[num]:=i;
   end;
  end;

  for i:=1 to num do
  begin
   if (mas[i]>=m) and (mas[i]<=n) then
   begin
    writeln (mas[i]);
    res:=true;
   end
   else if mas[i]>n then break;
  end;

 if res=false then writeln ('Absent');
 close (input);
 close (output);
end.
