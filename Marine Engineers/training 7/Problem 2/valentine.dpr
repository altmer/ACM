program valentine;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [0..10000] of string;
    b : string;
    n,i,j,ans, cur, max:integer;

procedure qs (var a : array of string; l, r : integer);
var
 i, j : integer;
 mid, t : string;

begin
 i:=l;
 j:=r;
 mid:=a[(i+j)div 2];
 repeat
  while a[i] < mid do inc (i);
  while a[j] > mid do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc(i);
   dec(j);
  end;
 until i>j;
 if l<j then qs (a,l,j);
 if r>i then qs (a,i,r);
end;

begin
  assign (input,'valentine.in');
  assign (output,'valentine.out');
  reset(input);
  rewrite(output);

  readln (n);
  for i:=0 to n-1 do
  begin
   readln (a[i]);
   a[i]:=lowercase(a[i])
  end;

  qs (a, 0, n-1);
  max:=0;
  cur:=1;
  for i:=1 to n-1 do
  begin
   if a[i] = a[i-1] then inc(cur)
    else
     begin
      if cur >= max then
       begin
        max:=cur;
        ans:=i-1;
       end;
      cur:=1; 
     end;
  end;

  writeln (a[ans]);
  close(input);
  close(output);
end.
