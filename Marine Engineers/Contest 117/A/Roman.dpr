program corporate;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var rom : array [1..14] of string = ('O', 'I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M');
    des : array [1..14] of integer = (0, 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000);
    mas : array [1..5500]of integer;
    s, cr : string;
    i, cur, ToPut, step, n, sum, cas : integer;

procedure enter;
var old, i, j : integer;

begin
 old:=0;
 i:=1;
 while i<=length(s) do
 begin
  if s[i]<>' ' then
  begin
   if (s[i]>'A') and (s[i]<'Z') then
   begin
    cr:='';
    cr:=cr+s[i];
    for j:=1 to 14 do
     if rom[j]=cr then
     begin
      Cur:=des[j];
      break;
     end;
    if cur<=old then Toput:=Toput+cur else toput:=toput-2*old+cur;
    old:=cur;
   end;
   inc(i);
  end

  else
  begin
   mas[step]:=toput;
   inc(step);
   toput:=0;
   inc(i);
   old:=0;
   cur:=0;
  end;
 end;
 mas[step]:=toput;
 inc(step);
 toput:=0;
end;

procedure outp (a : integer);
var i, j : integer;

begin
 i:=14;
 while (i>0) and (a>0) do
 begin
  if a div des[i]<>0 then
  begin
   for j:=1 to (a div des[i]) do
    write (rom[i]);
   a:=a-des[i]*(a div des[i]);
  end
  else dec(i);
 end;
end;

begin
 assign (input,'input.txt');
 assign (output,'output.txt');
 reset(input);
 rewrite(output);

 n:=1;
 cas:=1;
 while n<>0 do
 begin
  readln (n);
  if n<>0 then
  begin
  step:=1;
  while step<>n+1 do
  begin
   readln (s);
   enter;
  end;


  sum:=0;
  for i:=1 to n do
   sum:=sum+mas[i];
  write ('Case ');
  outp(cas);
  write(': ');
  outp(sum);
  inc(cas);
  writeln;
  end;    
 end;

 

 close(input);
 close(output);
end.
