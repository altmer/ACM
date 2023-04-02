program T1370;

{$APPTYPE CONSOLE}
uses
  SysUtils;


var a : array [0..100] of integer;
    n, i : integer;
    ans : extended;

procedure QS (var a : array of integer; l, r : integer);
var mid, t : integer;
    i, j : integer;

begin
 mid:=a[(l+r)div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]>mid do inc (i);
  while a[j]<mid do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc(i);
   dec(j);
  end;
 until i>j;
 if i<r then QS (a, i, r);
 if j>l then QS (a, l, j);
end;

begin
 assign (input,'T1161.in');
 reset (input);
 assign (output,'T1161.out');
 rewrite(output);

 readln (n);
 for i:=0 to n-1 do
  readln (a[i]);

 QS (a, 0, n-1);
 ans:=a[0];
 for i:=1 to n-1 do
  ans:=2*sqrt(ans*a[i]);

 writeln (ans : 0 : 2);

 close (input);
 close (output);
end.



