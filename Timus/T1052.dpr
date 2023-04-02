program T1052;
{$apptype console}

uses
  sysutils;

type coord = record
      x, y : integer;
     end;

var point : array [1..200] of coord;
    ang : array [0..200] of real;
    i, j,  n, cur, ans : integer;

procedure qs (var a : array of real; l, r : integer);
var
 i, j : integer;
 mid, t : real;

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

function Cosin (v : coord) : real;

begin
 cosin:=(v.x/sqrt(sqr(v.x)+sqr(v.y)));
end;

procedure angles (k : integer);
var vector : coord;
    i : integer;

begin
 for i:=k+1 to n do
 begin
  vector.x:=point[k].x-point[i].x;
  vector.y:=point[k].y-point[i].y;
  ang [i-k-1]:=cosin(vector);
 end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1052.in');
 reset(input);
 assign(output, 'T1052.out');
 rewrite(output);
{$ENDIF}

 readln (n);
 for i:=1 to n do readln (point[i].x, point[i].y);

 ans:=0;
 for i:=1 to n-1 do
 begin
  for j:=0 to n do ang[j]:=0;
  angles (i);
  qs (ang, 0, n-i-1);
  cur:=2;  
  for j:=1 to n-i do
  begin
   if ang[j]=ang[j-1] then inc (cur)
    else
    begin
     if cur>ans then ans:=cur;
     cur:=2;
    end;
   end;
 end;

 writeln (ans);
 
{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
