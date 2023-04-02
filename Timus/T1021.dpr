program T1021;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var i : integer;
    n, m : integer;
    a, b : array [1..50000] of integer;
    fin : boolean;

function BinSearch (x : integer; l, r : integer) : boolean;

begin
 if r-l<>1 then
 begin
  if b[(l+r) div 2] < x then BinSearch:=BinSearch (x, l, (l+r) div 2)
   else if b[(l+r) div 2] > x then BinSearch:=BinSearch (x, (l+r) div 2, r)
    else
    begin
     BinSearch:=true;
     exit;
    end;
 end

 else if (b[r]=x) or (b[l]=x) then BinSearch:=true else BinSearch:=false;
end;

begin
 assign (input,'T1021.in');
 reset (input);
 assign (output,'T1021.out');
 rewrite(output);

 readln (n);
 for i:=1 to n do readln (a[i]);

 readln (m);
 for i:=1 to m do readln (b[i]);

 for i:=1 to n do
 begin
  fin:=Binsearch(10000 - a[i], 1, m);
  if fin then break;
 end;

 if fin then writeln ('YES') else writeln ('NO');

 close (input);
 close (output);
end.



