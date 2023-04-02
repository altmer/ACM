program longprod;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
 max = 5001;

type
 mas = array [1..max] of byte;

var m, n, a, b, res : mas;
    c : char;
    i,j : integer;
    t : byte;
    len_m, len_n, len_a : integer;
    fin : boolean;

procedure set0 (var a : mas);
var i : integer;

begin
 for i:=1 to len_a do
  a[max-i+1]:=0;
end;

procedure shift (a : mas; n : integer; var b : mas);
var i : integer;

begin
 for i:=len_a downto 1 do
  b[max-i-n+1]:=a[max-i+1];
 for i:=n downto 1 do
  b[max-i+1]:=0;
end;

procedure add (a, b : mas; len : integer; var c:mas);
var perep : integer;
    i : integer;

begin
 perep:=0;
 i:=1;
 while i<=len do
 begin
  c[max-i+1]:=a[max-i+1]+b[max-i+1]+perep;
  perep := c[max-i+1] div 10;
  c[max-i+1]:=c[max-i+1] mod 10;
  if (i=len) and (perep<>0) then inc (len);
  inc(i);
 end;
end;

procedure mult_digit (a : mas; b : byte;var len : integer; var c : mas);
var i : integer;
    carry : byte;

begin
 carry:=0;
 i:=1;
 while i <=len do
  begin
   c[max-i+1]:=c[max-i+1]+a[max-i+1]*b+carry;
   carry:=c[max-i+1] div 10;
   c[max-i+1]:=c[max-i+1] mod 10;
   if (carry<>0) and (i=len) then inc (len);
   inc(i);
  end;
end;

begin
 assign (input,'longprod.in');
 reset (input);
 assign (output,'longprod.out');
 rewrite(output);

 i:=1;
 while not eoln do
 begin
  read(c);
  m[max-i+1]:=ord(c)-ord('0');
  inc(i);
 end;
 readln;
 len_m:=i-1;
 j:=1;
 for i:=len_m downto (len_m div 2)+1  do
 begin
  t:=m[max-i+1];
  m[max-i+1]:=m[max-j+1];
  m[max-j+1]:=t;
  inc(j);
 end;

 i:=1;
 while not eoln do
 begin
  read(c);
  n[max-i+1]:=ord(c)-ord('0');
  inc(i);
 end;
 readln;
 len_n:=i-1;
 j:=1;
 for i:=len_n downto (len_n div 2)+1 do
 begin
  t:=n[max-i+1];
  n[max-i+1]:=n[max-j+1];
  n[max-j+1]:=t;
  inc(j);
 end;
 
//multiplication
 for i:=1 to len_m do
 begin
  set0 (a);
  set0 (b);
  len_a:=len_n+(i-1);
  shift (n, i-1, a);
  mult_digit (a,m[max-i+1],len_a, b);
  add (res, b, len_a, res);
 end;

 for i:=1 to max do
  if res[i]<>0 then
  begin
   for j:=max-i+1 downto 1 do write(res[max-j+1]);
   fin := true;
   break;
  end;
 if fin=false then writeln ('0');
 close (input);
 close (output);
end.
