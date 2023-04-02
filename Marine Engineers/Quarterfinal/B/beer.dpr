program beer;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, k, i, j, cur : integer;
    notsimple : boolean = false;
    s : integer = 2000000000;
    ans : array [1..3] of integer;

begin
 assign (input,'beer.in');
 reset (input);
 assign (output,'beer.out');
 rewrite(output);

 readln (n);

 for i:=2 to round(sqrt(n)) do
  if n mod i = 0 then
  begin
   notsimple:=true;
   break;
  end;

 if not notsimple then writeln (n, ' 1 1')

 else
 begin
  for i:=1 to 1000 do
   for j:=1 to 1000 do
   begin
    if ((n mod i) mod j = 0) then
    begin
     k:=(n div i) div j;
     if k*i*j=n then
     begin
      cur:=2*(i*j+j*k+i*k);
      if cur<s then
      begin
       s:=cur;
       ans[1]:=i;
       ans[2]:=j;
       ans[3]:=k;
      end;
     end;
    end;
   end;
  writeln (ans[1], ' ', ans[2], ' ', ans[3]);
 end;

 close (input);
 close (output);
end.
