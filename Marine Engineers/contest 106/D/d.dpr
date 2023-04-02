program c;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var a : array [1..10000] of integer;
    dv : array [1..10000] of boolean;
    n, k : int64;
    i, j : integer;
    answer : int64;
    lim : int64;
    t : integer; 

begin
 assign (input,'d.in');
 assign (output,'d.out');
 reset(input);
 rewrite(output);

 readln (n, k);
 answer:=0;
 j:=1;
 for i:=n-k+1 to n do
 begin
  a [j]:=i;
  dv [i]:=true;
  inc(j);
  inc (answer);
 end;

 for j:=1 to k do
 begin
  lim:=round(sqrt(a[j]));
  t:=2;
  while t <= lim  do
  begin
   if a[j] mod t = 0 then
   begin
    if  not dv[t] then
    begin
     dv[t]:=true;
     inc (answer);
    end;
    if not dv[a[j] div t] then
    begin
     dv[a[j] div t]:=true;
     inc (answer);
    end;
   end;
   inc (t);
  end;
 end;
 inc (answer);
 writeln (answer);
 

 close(input);
 close(output);
end.
