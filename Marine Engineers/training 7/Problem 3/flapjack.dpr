program flapjack;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
 olad = array [1..30] of integer;

var ans : array [1..200000] of integer;
    a, b : olad;
    n,i,j, max, pos, st :integer;
    fin : boolean;

procedure qs (var a : olad; l, r : integer);
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

procedure flip (var a : olad; k : integer);
var i, t : integer;

begin
 for i:=0 to ((k div 2) -1) do
 begin
  t:=a[k-i];
  a[k-i]:=a[i+1];
  a[i+1]:=t;
 end;
end;

begin
  assign (input,'flapjack.in');
  assign (output,'flapjack.out');
  reset(input);
  rewrite(output);

  i:=1;
  while not seekeof do
  begin
   read (a[i]);
   inc (i);
  end;

  j:=1;
  n:=i;
  st:=i-1;
  b:=a;
  qs (b, 1, st);

  for i:=1 to st do if a[i]=b[i] then fin:=true else begin fin:=false; break; end;

  while fin=false do
  begin
   for i:=st downto 1 do if a[i]>max then begin  max:=a[i]; pos:=i; end;

   if pos = 1 then
    begin
     flip (a, st);
     ans [j]:=n-st;
     inc (j);
    end
     else if pos<>st then
     begin
      flip (a, pos);
      flip (a, st);
      ans [j]:=n-pos;
      inc(j);
      ans [j]:=n-st;
      inc (j);
     end;

   for i:=1 to n-1 do if a[i]=b[i] then fin:=true else begin fin:=false; break; end;
   dec(st);
   max:=0;
  end;

  ans[j]:=0;
  for  i:=1 to j do write (ans[i], ' ' );
  close(input);
  close(output);
end.
