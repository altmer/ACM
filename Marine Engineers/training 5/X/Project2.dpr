program Project2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

const max = 100;

type mas = array[1..max] of integer;

var i, k, j :integer;
    aq, bq, sum : string;
    a,b,c, d : mas;
    res:boolean;

procedure add (a, b : mas; var c:mas);
var perep : integer;
 i : integer;

begin
 perep:=0;
 for i:=max downto 1 do
 begin
  c[i]:=a[i]+b[i]+perep;
  perep := c[i] div 10;
  c[i]:=c[i] mod 10;
 end;
end;

procedure sub (a, b : mas; var c:mas);
var perep : integer;
 i : integer;

begin
 perep:=0;
 for i:=max downto 1 do
 begin
  c[i]:=a[i]-b[i]+perep;
  if c[i] < 0 then
   begin
    perep:=-1;
    c[i]:=c[i]+10;
   end
  else perep := 0;
 end;
end;

 begin
  assign(input,'x_number.in');
  reset (input);
  assign(output,'x_number.out');
  rewrite(output);
  readln (aq);
  readln (bq);
  readln (sum);
  j:=0;
  for i:=length(aq) downto 1 do
  begin
   a[max-j]:= ord (aq[i])-48;
   j:=j+1;
  end;

  j:=0;
  for i:=length(bq) downto 1 do
  begin
   b[max-j]:= ord (bq[i])-48;
   j:=j+1;
  end;

  j:=0;
  for i:=length(sum) downto 1 do
  begin
   c[max-j]:= ord (sum[i])-48;
   j:=j+1;
  end;

  if length (aq)=0 then
   sub (c,b,d)
  else if length (bq)=0 then
   sub (c, a, d)
  else
   add(a, b, d);

   for i:=1 to max do
   if d[i]<> 0 then
    begin
     for j:=i to max do write(d[j]);
     res:=true; break;
    end;
   if res=false then write('0');

  close(input);
  close(output);
end.
