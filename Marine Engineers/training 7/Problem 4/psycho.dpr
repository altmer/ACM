program psycho;

{$APPTYPE CONSOLE}
uses
  SysUtils;
type
 mas = array [0..100000] of integer;

var a, b : mas;
    n, s, i, ss, iss :integer;

procedure qs (var a : mas; l, r : integer);
var
 i, j : integer;
 mid, t : integer;

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

procedure search (ss, l, r : integer; var iss : integer);

begin
  if (b [(l+r)div 2] > ss) and (r-l<>1) then search (ss, l, (l+r) div 2, iss);
  else if (b[(l+r) div 2] < ss) and (r-l<>1) then search (ss, (l+r) div 2, r, iss);
  else if r-l<>1 then iss:=b[(l+r)div 2];
end;

Begin
  assign (input,'psycho.in');
  assign (output,'psycho.out');
  reset(input);
  rewrite(output);
  readln (n, s);

  for i:=0 to n-1 do readln (a[i], b[i]);

  qs (a, 0, n-1);
  qs (b, 0, n-1);

  for i:=0 to n-1 do
  begin
   ss:=s-a[i];
   search (ss, 0, n-1, iss);
   if iss<>0 then
   begin
    writeln (a[i], ' ', iss);
    halt;
   end;
  end;
  
  close(input);
  close(output);
end.
