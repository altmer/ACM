program T1370;

{$APPTYPE CONSOLE}
uses
  SysUtils;


var n, m, i : integer;
    a : array [1..1000] of integer; 

begin
 assign (input,'T1370.in');
 reset (input);
 assign (output,'T1370.out');
 rewrite(output);

 readln (n, m);
 for i:=1 to n do
  readln (a[i]);

 m := m mod n;

 if m+10<= n then
  for i:=m+1 to m+10 do write (a[i])

 else
 begin
  m:=n-m;
  for i:=n-m+1 to n do
   write (a[i]);
  for i:=1 to 10-m do
   write(a[i]);
 end;
 
 
 close (input);
 close (output);
end.



