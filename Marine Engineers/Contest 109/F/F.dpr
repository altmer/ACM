program Abc;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type mas = record
      val, num, l, r, cur : integer;
      end;

var a : array [0..100000] of mas;
    b : array [0..3] of integer;
    q, number, i, j, l, r : integer;
    n : integer = -1;
    max, k : integer;

function det (a, b, c, d, num : integer) : integer;
var t : integer;

begin
 if a>c then
 begin
  if b>d then t:= d-a else t:=b-a;
 end

 else
 begin
  if b>d then t:=d-c else t:=b-c;
 end;
 if t > num then det:=num else det:=t+1;
end;

begin
 assign (input,'frequent.in');
 assign (output,'frequent.out');
 reset(input);
 rewrite(output);
 while n<>0 do
 begin
  readln (n, q);
  number:=0;
  if n<>0 then
  begin
  a[0].val:=0;
  for i:=0 to number do
   a[i].cur:=0;
  j:=0;
  for i:=1 to n do
  begin
   read (number);
   if number=a[j].val then
   begin
    a[j].num:=a[j].num+1;
    a[j].r:=i;
   end

   else
    begin
     inc (j);
     a[j].val:=number;
     a[j].num:=1;
     a[j].l:=i;
     a[j].r:=i;
    end;
  end;

  number:=j+1;
  for i:=1 to q do
  begin
   readln (l, r);

   for j:=1 to number do
    if (a[j].r<l) or (a[j].l>r) then a[j].cur:=0
    else
     a[j].cur:=det (l, r, a[j].l, a[j].r, a[j].num);
    Max:=0;
    for k:=1 to number do
     if a[k].cur >max then max:=a[k].cur;
    writeln (max);
   end;
  end;
 end;

 close(input);
 close(output);
end.
