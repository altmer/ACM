program conhull;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type point = record
      x, y : extended;
     end;

const max = 10000;

var a : array [1..max] of point;
    color : array [1..max] of boolean;
    d, ToNext : point;
    cur, n, i, next : integer;
    len, cosin, sp, cosin_next, len_next, ans : extended;

function FindFirst : integer;
var i : integer;
    ans : point;

begin
 ans:=a[1];
 result:=1;
 for i:=2 to n do
  if a[i].y<ans.y then
  begin
   ans:=a[i];
   result:=i;
  end

  else if a[i].y=ans.y then
   if a[i].x<ans.x then
   begin
    ans:=a[i];
    result:=i;
   end;
end;

function ScalMult (d, ToNext : point) : extended;

begin
 result := d.x*tonext.x+d.y*tonext.y; 
end;

function Leng (Tonext : point) : extended;

begin
 Leng:=sqrt (sqr (tonext.x)+sqr(tonext.y));
end;

begin
 assign(input,'conhull.in');
 reset (input);
 assign(output,'conhull.out');
 rewrite(output);

 readln (n);
 for i:=1 to n do
  readln (a[i].x, a[i].y);

 ans:=0;

 cur:=FindFirst;
 color[cur]:=true;

 d.x := -1;
 d.y :=  0;

 while true do
 begin
  cosin_next:=-2;
  len_next:=0;

  for i:=1 to n do
  begin
   tonext.x:=a[i].x-a[cur].x;
   tonext.y:=a[i].y-a[cur].y;
   sp := ScalMult (d, tonext);
   len := Leng (tonext);
   if len<>0 then cosin:=sp/len
    else cosin:=-2;

   if cosin>cosin_next then
   begin
    next:=i;
    cosin_next:=cosin;
    len_next:=len;
   end

   else if cosin=cosin_next then
    if len<len_next then
    begin
     next:=i;
     cosin_next:=cosin;
     len_next:=len;
    end;
  end;
  ans:=ans+len_next;
  if color[next] then break;
  color[next]:=true;
  d.x:=(a[next].x-a[cur].x)/len_next;
  d.y:=(a[next].y-a[cur].y)/len_next;
  cur:=next;
 end;

 writeln (ans : 0 : 1);

 
 close(input);
 close(output);
end.
