program Abc;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type MYtype = record
      a,b : real;
      end;

var angle: array [0..10001] of MYtype;
    q , p, MinAngle: real;
    test, Mytest, i, n, FirstPoint, SecondPoint: integer;
    Borderup : integer;
    min1, min2 : real;
    dist : real;

function bin_search (a : real; l, r : integer) : integer;
var cur : integer;
begin
 cur:=l+((r-l) div 2);
 if angle[cur].a > a then
 begin
  if angle[cur-1].a< a
   then bin_search:=cur
    else bin_search:=bin_search(a, l, cur);
 end

 else if angle[cur].a<a then
 begin
  if angle[cur+1].a>a
   then bin_search:=cur+1
    else bin_search:=bin_search(a, cur, r);
 end

 else bin_search:=cur;
end;


begin
 assign (input,'knights.in');
 assign (output,'knights.out');
 reset(input);
 rewrite(output);

readln(test);

for mytest:=1 to test do
begin

 MinAngle:=20;
 FirstPoint:=0;
 SecondPoint:=0;
 readln(n);
 for i:=1 to n do
 begin
  readln(p,q);
  angle[i].a:=2*pi*p/q;
 end;

  angle[0].a:=angle[n].a-2*pi;
  angle[n+1].a:=angle[1].a+2*pi;

  for i:=1 to n do
   if angle[i].a <= pi
    then angle[i].b:=angle[i].a+pi
     else angle[i].b:=angle[i].a-pi;

  for i:=1 to n do
  begin
   BorderUp:=bin_search (angle[i].b, 0, n+1);
   min1:=angle[BorderUp].a-angle[i].b;
   if borderup-1 >=0 then min2:=angle[i].b-angle[BorderUp-1].a;
   if min1<min2 then
   begin
    if min1<minAngle then
    begin
     minAngle:=min1;
     FirstPoint:=i;
     SecondPoint:=borderup;
    end;
   end
   else
   begin
    if min2<minAngle then
    begin
     minAngle:=min2;
     if borderup-1 >=0 then FirstPoint:=Borderup-1;
     SecondPoint:=i;
    end;
   end;
  end;

 dist:=(n*sqrt(2*(1-cos(angle[SecondPoint].a-angle[FirstPoint].a))));
 writeln ('Scenario #', myTest, ':');
 writeln (dist:0:2);
 writeln;

 end;
 close(input);
 close(output);
end.
