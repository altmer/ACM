program T1026;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [0..100000] of word;
    i, n, k : integer;

procedure QS (var a : array of word; l, r : integer);
var mid, t : word;
    i, j  : integer;
begin
 mid:=a[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]<mid do inc (i);
  while a[j]>mid do dec (j);
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
 assign (input,'T1026.in');
 reset (input);
 assign (output,'T1026.out');
 rewrite(output);

 readln (n);
 for i:=0 to n-1 do readln (a[i]);
 readln;
 QS (a, 0, n-1);
 readln (n);
 for i:=1 to n do
 begin
  readln (k);
  writeln (a[k-1]);
 end;

 close (input);
 close (output);
end.



