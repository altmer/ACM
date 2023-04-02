program G;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type coord = record
      x, y : real;
     end;

     vector = record
      c : real;
      p : integer;
     end;

var a : array [1..300] of coord;
    mas : array [1..300, 1..300] of boolean;
    vect : array [0..300] of vector;
    st, en : integer;
    n, i, j, k, w, l : integer;
    len, max, ans : real;

procedure QS (var a : array of vector; l, r : integer);
var t, mid : vector;
    i, j : integer;

begin
 i:=l; j:=r;
 mid:=a[(l+r) div 2];
 repeat
  while a[i].c>mid.c do inc (i);
  while a[j].c<mid.c do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc (i);
   dec (j);
  end;
 until i>j;
 if j>l then QS (a, l, j);
 if i<r then QS (a, i, r); 
end;

function cosin (a,b : coord) : extended;
var vec : coord;

begin
 vec.x := b.x-a.x;
 vec.y := b.y-a.y;
 cosin := vec.x/(sqrt(sqr(vec.x)+sqr(vec.y))); 
end;

begin
 assign (input, 'input.txt');
 assign (output, 'output.txt');
 reset (input);
 rewrite (output);
 ans:=0;

 readln (n);
 for i:=1 to n do
  readln (a[i].x, a[i].y);
 
 for i:=1 to n-1 do
 begin

  for j:=i+1 to n do
  begin
   vect[j-i].c:=cosin(a[i], a[j]);
   vect[j-i].p:=j;
  end;

  w:=n-i;
  qs (vect, 1, w);
  k:=1;
  while k<=w do
  begin
   st:=k;
   while (vect[k+1].c=vect[k].c) and (k<w) do
   begin
    inc(k);
   end;
   max:=0;
   for j:=st to k do
   if not mas[i,vect[j].p] then
    begin
     mas[vect[j].p,i]:=true;
     mas[i,vect[j].p]:=true;
     for l:=j to k do
     begin
      mas[vect[j].p, vect[l].p]:=true;
      mas[vect[l].p, vect[j].p]:=true;
     end;
     len:=sqrt(sqr(a[vect[j].p].x-a[i].x)+sqr(a[vect[j].p].y-a[i].y));
     if len>max then max:=len;
    end;
   ans:=ans+max;
   inc(k);
  end;
 end;

 writeln (round(ans));

 close (input);
 close (output);
end.
