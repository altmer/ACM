program super;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const max=100;

type location = record
      x, y : real;
       end;

     distance = record
      dis : real;
      st, en : byte;
       end; 

var t, n : integer;
    i, l, j, k, p, temp : integer; 
    a : array [1..max] of location;
    d : array [0..9999] of distance;
    is_comp : array[1..max] of byte;
     len : integer;
    fin : boolean;
    ans : real;

procedure qs (var a : array of distance; l, r : integer);
var
 i, j : integer;
 mid, t : distance;

begin
 i:=l;
 j:=r;
 mid:=a[(i+j)div 2];
 repeat
  while a[i].dis < mid.dis do inc (i);
  while a[j].dis > mid.dis do dec (j);
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
 assign (input,'super.in');
 reset (input);
 assign (output,'super.out');
 rewrite(output);

 readln (t);
 for i:=1 to t do
 begin
  l:=0;
  ans:=0;
  fin:=false;
  for p:=1 to n do
  begin
   a[p].x:=0;
   a[p].y:=0;
   is_comp[p]:=0
  end;
  for p:=0 to len do
  begin
   d[p].dis:=0;
   d[p].st:=0;
   d[p].en:=0;
  end;


 
  readln (n);
  for j:=1 to n do
  begin
   readln (a[j].x, a[j].y);
   k:=1;
   while j-k>0 do
   begin
    d[l].dis:=sqrt(sqr(a[j].x - a[j-k].x)+sqr(a[j].y-a[j-k].y));
    d[l].st:=j;
    d[l].en:=j-k;
    inc(k);
    inc(l);
   end;
  end;
  qs (d,0,l-1);
  len:=l-1;
  l:=0;
  k:=1;
  while not fin do
  begin
   if (is_comp[d[l].st]=0) or (is_comp[d[l].en]=0) or (is_comp[d[l].en]<>is_comp[d[l].st])
    then ans:=ans+d[l].dis;

   if (is_comp[d[l].st]=0) and (is_comp[d[l].en]=0) then
   begin
    is_comp[d[l].st]:=k;
    is_comp[d[l].en]:=k;
   end
   else if is_comp[d[l].st]=0 then is_comp[d[l].st]:=is_comp[d[l].en]
    else if is_comp[d[l].en] = 0 then is_comp[d[l].en]:=is_comp[d[l].st]
     else if is_comp[d[l].en]<>is_comp[d[l].st] then
     begin
      temp:=is_comp[d[l].en];
      for p:=1 to n do if is_comp[p]=temp then is_comp[p]:=is_comp[d[l].st];
     end;
   inc(k);

   for p:=2 to n do if is_comp[p]<>is_comp[p-1] then
   begin
    fin:=false;
    break;
   end
   else fin:=true;
   inc (l);
  end;
  writeln (ans : 0 : 2);
 end;


 close (input);
 close (output);
end.



