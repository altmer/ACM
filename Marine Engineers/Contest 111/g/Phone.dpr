program Nested;
{$APPTYPE CONSOLE}

uses
  SysUtils;

type matr = record
      w, h : integer;
      end;

var cur, test : integer;
    a : array [0..20000] of matr;

procedure QS (var a : array of matr;  l, r : integer);
var mid, t : matr;
    k, m : integer;

begin
 k:=l;
 m:=r;
 mid:=a[(k+m) div 2];
 repeat
 while  a[k].w<mid.w do inc (k);
 while  a[m].w>mid.w do dec (m);
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
  assign(input,'dolls.in');
  reset(input);
  assign(output,'dolls.out');
  rewrite(output);
  readln (test);
  for cur:=1 to test do
  begin
   readln (n);
   for i:=1 to n do read (a[i].w, a[i].h);
   readln;
   QS(a, 0, n-1);
   num:=n-1;
   k:=0;
   while num>0 do
   begin
    for i:=k to n-1 do
    begin

    end;



   end;

  end;
  close(input);
  close(output);
end.
