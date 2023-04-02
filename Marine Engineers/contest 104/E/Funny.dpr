program E;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type LKS = record
      col, len, stn : integer;
      end;

     mas = record
      c : boolean;
      num : integer;
      end;

var color : array [1..200000] of mas;
    a : array [1..200000] of LKS;
    max : LKS;
    i, n, length, st, j, k : integer;

begin
 assign (input,'funny.in');
 assign (output,'funny.out');
 reset(input);
 rewrite(output);
 readln (n);
 length:=0;
 st:=1;
 for i:=1 to n do
 begin
  read (a[i].col);
   if (color [a[i].col].c = false) or (color [a[i].col].num < st) then
   begin
    color [a[i].col].c := true;
    color [a[i].col].num := i;
    inc(length);
    a[i].len:=length;
    a[i].stn:=st;
   end
   else
   begin
    j:=color [a[i].col].num+1;
    color [a[i].col].num:=i;
    length:=i-j+1;
    st:=j;
    a[i].len:=length;
    a[i].stn:=st;
   end;
 end;

 for i:=1 to n do
  if a[i].len>max.len then max:=a[i];
 writeln (max.len);
 writeln (max.stn);

 close(input);
 close(output);
end.
