program D2;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [0..100000] of integer;
    ex : array [0..100000] of boolean;
    n, l, i, left, res, F, st, ToFind : integer;

function bin_search (TF : integer; l, r : integer) : integer;
var k, h : integer;
    fin : boolean;

begin
  h:=1;
  bin_search:=-1;
  fin:=false;
  if r-l>1 then
  begin
   k:=l+((r-l)div 2);
   if (TF>=a[k]) then
   begin
    h:=k-1;
    while (a[k]<=TF) and (k<n) do
    begin
     if not ex[k] then
     begin
      bin_search:=k;
      fin:=true;
     end;
     inc(k);
    end;
    if (not fin) and (h>=0) then bin_search:=bin_search(TF,l,h);
   end

   else
   begin
    bin_search:=bin_search (TF,l, k);
   end;
  end

  else
  begin
   if (a[r]<=TF) and (not ex[r]) then
   begin
    bin_search:=r;
   end
   else if (a[l]<=TF) and (not ex[l]) then
   begin
    bin_search:=l;
   end

   else bin_search:=-1;
  end;
end;

procedure QS (var a : array of integer;  l, r : integer);
var mid, t : integer;
    k, m : integer;

begin
 k:=l;
 m:=r;
 mid:=a[(k+m) div 2];
 repeat
 while  a[k]<mid do inc (k);
 while  a[m]>mid do dec (m);
 if k<=m then
 begin
  t:=a[k];
  a[k]:=a[m];
  a[m]:=t;
  k:=k+1;
  m:=m-1;
 end;
 until k>m;

 if l<m then QS (a, l, m);
 if k<R then QS (a, k, R);
end;

begin
 assign (input,'binpacking.in');
 assign (output,'binpacking.out');
 reset(input);
 rewrite(output);
 res:=0;
 readln (n);
 readln (l);
 for i:=0 to n-1 do
  readln (a[i]);

 QS (a, 0, n-1);

 left:=n;
 st:=n-1;
 while left>0 do
 begin
  ToFind:=l-a[st];
  if not ex[st] then
  begin
  ex[st]:=true;
  F:=bin_search (ToFind, 0, n-1);
  if F<>-1 then
  begin
   left:=left-2;
   ex[f]:=true;
  end

  else
  begin
   dec(left);
  end;
  inc(res);
  end;
  dec(st);
 end;
 writeln (res);
 close(input);
 close(output);
end.
