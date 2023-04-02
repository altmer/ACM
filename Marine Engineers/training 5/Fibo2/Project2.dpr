program Project2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

const max = 50;

type mas = array[0..max-1] of byte;

var i, k, j :integer;
    a,b,c : mas;
    res:boolean;
procedure add (a, b : mas; var c:mas);
var perep : integer;
 i : integer;

begin
 perep:=0;
 for i:=(max-1) downto 0 do
 begin
  c[i]:=a[i]+b[i]+perep;
  perep := c[i] div 10;
  c[i]:=c[i] mod 10;
 end;
end;

 begin
  assign(input,'fibo2.in');
  reset (input);
  assign(output,'fibo2.out');
  rewrite(output);
  readln (a[max-1], b[max-1]);
  readln (k);
  if k=1 then c:=b

  else
  for i:=1 to k-1 do
   begin
    add (a, b, c);
    a:=b;
    b:=c;
   end;
  res:=false;
  for i:=0 to max-1 do
   if c[i]<> 0 then
    begin
     for j:=i to max-1 do write(c[j]);
     res:=true; break;
    end;
   if res=false then write('0');
  close(input);
  close(output);
end.
