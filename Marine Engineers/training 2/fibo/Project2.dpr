program Project2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var i:integer;
    a,e,b,c,x,k:int64;
    q:array[1..100] of int64;
begin
  assign(input,'fibo.in');
  reset (input);
  assign(output,'fibo.out');
  rewrite(output);
  read (q[1]);
  readln (q[2]);
  read(c);
  for i:=3 to (c+1) do
   begin
   q[i]:=(q[i-1]mod 100000)+(q[i-2]mod 100000) ;
   end;
  x:=abs(q[c+1] mod 100000);
  writeln(x);

  close(input);
  close(output);
end.
 