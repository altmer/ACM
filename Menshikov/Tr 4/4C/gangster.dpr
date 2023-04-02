program gangster;
{$APPTYPE CONSOLE}
uses
  SysUtils;

type gang = record
      t, p, s : integer;
      end;

var n, k,t, i, cur, ans, j : integer;
    g : array [0..100] of gang;
    amax : array [0..100] of integer; 

procedure QS (var a : array of gang; L,R: integer);
var i,j : integer;
    Mid,T : gang;

begin
 i:=l; j:=R; Mid:=a[(i+j) div 2];
 repeat
  while A[i].t<Mid.t do inc(i);
  while a[j].t>Mid.t do dec(j);
  if i<=j then
   begin
    t:=a[i];
    a[i]:=a[j];
    a[j]:=t;
    inc(i);
    dec(j);
   end;
 until i>j;
 if L<j then QS(A,L,j);
 if i<R then QS(A,i,R);
end;

begin

 readln (n, k, t);
 for i:=0 to n-1 do
  read (g[i].t);
 readln;
 for i:=0 to n-1 do
  read (g[i].p);
 readln;
 for i:=0 to n-1 do
  read (g[i].s);

 QS (g, 0, n-1);

 for i:=0 to n-1 do
  if g[i].s>g[i].t then g[i].p:=0;

 for i:=0 to n-1 do
 begin
  amax[i]:=g[i].p;
  j:=i-1;
  while j>=0 do
  begin
   if g[i].t-g[j].t>=abs(g[i].s-g[j].s) then
   begin
    cur:=g[i].p+amax[j];
    if cur>amax[i] then amax[i]:=cur;
   end;
   dec(j);
  end;
 end;

 ans:=g[0].p;
 for i:=1 to n-1 do
  if amax[i]>ans then ans:=amax[i];

 writeln (ans);

 close(input);
 close(output);
end.
