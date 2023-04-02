program T1086;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i, k, n, count : integer;
    mas : array [1..15000] of integer;
    lim : real;
    res : boolean;

begin
 assign (input, 'T1086.in');
 reset (input);
 assign (output,'T1086.out');
 rewrite(output);

 mas[1]:=2;
 mas[2]:=3;
 mas[3]:=5;
 mas[4]:=7;

 count:=5;
 while count<=15000 do
 begin
  for i:=mas[count-1]+1 to 170000 do
  begin
   res:=false;
   k:=1;
   lim:=sqrt(i);
   while mas[k]<=lim do
   begin
    if i mod mas[k]=0 then
    begin
     res:=true;
     break;
    end;
    inc(k);
   end;
   if not res then break;
  end;
  if not res then
  begin
   mas[count]:=i;
   inc(count);
  end;
 end;

 readln (k);
 for i:=1 to k do
 begin
  readln (n);
  writeln (mas[n]);  
 end;

 close (input);
 close (output);
end.
