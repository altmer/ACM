program H;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var cur, test : integer;
    a : array [0..20000] of integer;
    ans, n, k, i : integer;

procedure QS (var a : array of integer;  l, r : integer);
var mid, t : integer;
    k, m : integer;

begin
 k:=l;
 m:=r;
 mid:=a[(k+m) div 2];
 repeat
 while  a[k]>mid do inc (k);
 while  a[m]<mid do dec (m);
 if k<=m then
 begin
  t:=a[k];
  a[k]:=a[m];
  a[m]:=t;
  k:=k+1;
  m:=m-1;
 end;
 until k>m;

 if l<m then QS (a, l, m);
 if k<R then QS (a, k, R);
end;


begin
 assign (input,'shopaholic.in');
 assign (output,'shopaholic.out');
 reset(input);
 rewrite(output);
 n:=1;
 readln (test);
 for cur:=1 to test do
 begin
  for i:=0 to n-1 do a[i]:=0;
  readln (n);
  ans:=0;
  for i:=0 to n-1 do read (a[i]);
  QS (a, 0, n-1);
  k:=2;
  while k<=n-1 do
  begin
   ans:=ans+a[k];
   k:=k+3;
  end;
  writeln (ans);
 end;


 close(input);
 close(output);
end.
