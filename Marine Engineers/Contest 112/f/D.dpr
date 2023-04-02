program Abc;
{$APPTYPE CONSOLE}

uses
  SysUtils;

type order = record
      m, d, dif : integer;
      end; 

var a : array [0..800000] of order;
    n, i, dif, res : integer;

procedure QS (var a : array of order;  l, r : integer);
var mid, t : order;
    k, m : integer;
begin
 k:=l;
 m:=r;
 mid:=a[(k+m) div 2];
 repeat
 while  a[k].dif>mid.dif do inc (k);
 while  a[m].dif<mid.dif do dec (m);
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
 assign (input,'hodgson.in');
 assign (output,'hodgson.out');
 reset(input);
 rewrite(output);
 readln (n);
 for i:=0 to n-1 do
 begin
  readln (a[i].m, a[i].d);
  a[i].dif:=a[i].d-a[i].m;
 end;
 QS (a, 0, n-1);
 dif:=a[0].dif;
 res:=1;
 for i:=1 to n-1 do
 begin
  if dif>=a[i].m then
  begin
   dif:=dif-a[i].m;
   inc(res);
  end;
 end;
 writeln (res);
 close(input);
 close(output);
end.
