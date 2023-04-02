program G2;

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

function vp (a,b : coord) : extended;
var vec : coord;

begin
 vp := a.x*b.y-a.y*b.x;
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
   vect[j-i].c:=(a[i], a[j]);
   vect[j-i].p:=j;
  end;

  w:=n-i;
  qs (vect, 1, w);


  k:=1;}

 {while k<=w do
  begin
   st:=k;
   while (vect[k+1].c=vect[k].c) and (k<w) do
   begin
    inc(k);
   end;
   max:=0;
   vect[st-1].p:=i;
   for j:=st-1 to k do
   begin
    for l:=j+1 to k do
    begin
     if not mas[vect[l].p,vect[j].p] then
     begin
      len:=sqrt(sqr(a[vect[l].p].x-a[vect[j].p].x)+sqr(a[vect[l].p].y-a[vect[j].p].y));
      if len>max then max:=len;
     end;
    end;
   end;
   ans:=ans+max;
   inc(k);
   for j:=st-1 to k-2 do
    for l:=j+1 to k-1 do
    begin
     mas[vect[l].p,vect[j].p]:=true;
     mas[vect[j].p,vect[l].p]:=true;
    end;
  end;}
 end;

 writeln (round(ans));

 close (input);
 close (output);
end.
