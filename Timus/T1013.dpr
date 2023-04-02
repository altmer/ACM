{$apptype console}

uses
	sysutils;

const max=3000;

type num = array [0..max] of integer;

var n, k, i : integer;
    a, b, c : num;

procedure conj_digit (a : num; b : integer; var c : num);
var i, len : integer;
    carry : byte;
    
begin
 carry:=0;
 len:=a[0];
 i:=1;
 while i <=len do
  begin
   c[max-i+1]:=c[max-i+1]+a[max-i+1]*b+carry;
   carry:=c[max-i+1] div 10;
   c[max-i+1]:=c[max-i+1] mod 10;
   if (carry<>0) and (i=len) then inc (len);
   inc(i);
  end;
 c[0]:=len;
end;

procedure add (a, b : num; var c:num);
var perep, len : integer;
 i : integer;

begin
 perep:=0;
 if a[0]>b[0] then len:=a[0] else len:=b[0];
 i:=1;
 while i<=len do
 begin
  c[max-i+1]:=a[max-i+1]+b[max-i+1]+perep;
  perep := c[max-i+1] div 10;
  c[max-i+1]:=c[max-i+1] mod 10;
  if (perep<>0) and (i=len) then inc(len);
  inc (i);
 end;
 c[0]:=len;
end;

procedure set0 (var a : num);
var i : integer;

begin
 for i:=1 to a[0] do
  a[max-i+1]:=0;
 a[0]:=0;
end;

procedure print_num (a : num);
var i : integer;

begin
 for i:=a[0] downto 1 do
  write (a[max-i+1]);
end;

begin
 assign (input,'T1013.in');
 reset (input);
 assign (output,'T1013.out');
 rewrite(output);

 read (n);
 read (k);

 a[0]:=1;
 a[max]:=1;
 b[0]:=1;
 b[max]:=k-1;

 for i:=2 to n do
 begin
  add (a, b, c);
  a:=b;
  set0(b);
  conj_digit (c, k-1, b);
 end;

 print_num (b);

 close (input);
 close (output);
end.



