program journey;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type tmy = record
      n, i : int64;
      end;

var n, t, i : integer;
    w, d, p, prof: array [0..1000] of tmy;
    ans : array [0..1000] of integer;

procedure QS (var a : array of tmy; l, r : integer);
var mid, t : tmy;
    i, j  : integer;
begin
 mid:=a[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a[i].n>mid.n do inc (i);
  while a[j].n<mid.n do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc (i);
   dec (j);
  end;
 until i>j;
 if i<r then QS (a,i,r);
 if j>l then QS (a,l,j);
end;

begin
 assign (input,'journey.in');
 reset (input);
 assign (output,'journey.out');
 rewrite(output);

 readln (n, t);
 for i:=0 to n-1 do
 begin
  read (w[i].n);
  w[i].i:=i;
 end;
 readln;
 for i:=0 to n-1 do
 begin
  read (d[i].n);
  d[i].i:=i;
 end;
 readln;
 for i:=0 to n-1 do
 begin
  read (p[i].n);
  p[i].i:=i;
 end;
 readln;

 for i:=0 to n-1 do
 begin
  prof[i].n:=p[i].n-t*d[i].n;
  prof[i].i:=p[i].i;
 end;
 QS (prof, 0, n-1);
 QS (w, 0, n-1);

 for i:=0 to n-1 do
  ans[prof[i].i]:=w[i].i;

 for i:=0 to n-1 do write (ans[i]+1, ' ');


 close (input);
 close (output);
end.
