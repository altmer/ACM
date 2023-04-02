program scale;
{$APPTYPE CONSOLE}

uses SysUtils;

const numlen = 6500;

type num = array [0..numlen] of byte;

var a, b : num;
    ch : char;
    ii, jj, i, len, rem, d : integer;

procedure addshort (var n : num; x : integer);
var i : integer;

begin
 i:=numlen;
 while x > 0 do
 begin
  x:=x+n[i];
  n[i]:=x mod 10;
  x:=x div 10;
  dec(i);
 end;
 if numlen-i > n[0] then n[0]:=numlen-i;
end;

procedure multshort (var n : num; x : integer);
var i, carry : integer;

begin
 carry:=0;
 i:=1;
 while i<=n[0] do
 begin
  carry:=carry+n[numlen-i+1]*x;
  n[numlen-i+1]:=carry mod 10;
  carry:=carry div 10;
  if (i=n[0]) and (carry<>0) then inc(n[0]);
  inc(i); 
 end;
end;

procedure divshort (var n : num; divisor : integer; var rem : integer);
var i : integer;

begin
 rem:=0;
 i:=n[0]-1;
 while i>=0 do 
 begin
  rem:=rem*10+n[numlen-i];
  n[numlen-i]:=rem div divisor;
  rem:=rem mod divisor;
  dec(i);
 end;
end;

function Zero (n : num) : boolean;

begin
 zero:=true;
 for i:=0 to n[0]-1 do
  if n[numlen-i]<>0 then
  begin
   zero:=false;
   exit;
  end; 
end;

procedure WriteAns (n : num);
var i : integer;

begin
 for i:=n[0]-1 downto 0 do
  if n[numlen-i]<=9 then
   write (chr(ord('0')+n[numlen-i]))
    else write (chr(ord('A')-10+n[numlen-i]));
end;

begin
 assign(input,'scale.in');
 reset (input);
 assign(output,'scale.out');
 rewrite(output);

 readln (ii, jj);

 while not eoln do
 begin
  read (ch);
  if (ch>='0') and (ch<='9') then
   d:=ord(ch)-ord('0')
    else
     d:=ord(ch)-ord('A')+10;
  multshort (a, ii);
  addshort (a, d);
 end;

 len:=-1;
 repeat
  inc(len);
  divshort (a, jj, rem);
  b[numlen-len]:=rem;
  inc (b[0]);
 until Zero (a);

 WriteAns (b);

 close(input);
 close(output);
end.
