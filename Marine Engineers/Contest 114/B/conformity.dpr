program conformity;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n : integer = 1;
    a : array [0..4] of integer;
    s : array [0..10000] of string;
    j, i, max, count : integer;
    ints : array[0..10000] of integer;

procedure QSI (var a : array of integer; l, r : integer);
var mid, t : integer;
    i, j  : integer;
begin
 mid:=a[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]<mid do inc (i);
  while a[j]>mid do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc (i);
   dec (j);
  end;
 until i>j;
 if i<r then QSI (a,i,r);
 if j>l then QSI (a,l,j);
end;

procedure QSS (var a : array of string; l, r : integer);
var mid, t : string;
    i, j  : integer;
begin
 mid:=a[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]<mid do inc (i);
  while a[j]>mid do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc (i);
   dec (j);
  end;
 until i>j;
 if i<r then QSS (a,i,r);
 if j>l then QSS (a,l,j);
end;


begin
 assign (input,'conformity.in');
 assign (output,'conformity.out');
 reset(input);
 rewrite(output);

 while n<>0 do
 begin
  for i:=0 to n-1 do
  begin
   s[i]:='';
   ints[i]:=0;
  end;
  readln (n);
  if n<>0 then
  begin
  for j:=1 to n do
  begin
   for i:=0 to 4 do read (a[i]);
   readln;
   QSI (a, 0, 4);
   for i:=0 to 4 do s[j-1]:=s[j-1]+inttostr(a[i]);
  end;
  QSS (s, 0, n-1);
  ints[0]:=1;
  for i:=1 to n-1 do
  begin
   if s[i]=s[i-1] then ints[i]:=ints[i-1]+1
    else ints[i]:=1;
  end;

  ints[n]:=1;
  max:=0;
  count:=0;
  for i:=1 to n do
   if ints[i]=1 then
    if ints[i-1]>max then
    begin
     max:=ints[i-1];
     count:=1;
    end
    else if ints[i-1]=max then inc (count);

  writeln (count*max);
  end;  
 end; 
 close(input);
 close(output);
end.
