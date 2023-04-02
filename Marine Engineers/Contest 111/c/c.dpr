program c;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var  test,timer,n,i,j :byte;
     ans : integer;
     x: array [1..20] of byte;
     temp : integer;

begin

 assign (input,'parking.in');
 assign (output,'parking.out');
 reset(input);
 rewrite(output);

 readln(test);
 for timer:=1 to test do
 begin
  readln(n);
  ans:=2000000;
  for i:=1 to n do read(x[i]);
  readln;
  for i:=0 to 99 do
  begin
   temp:=0;
   for j:=1 to n do temp:=temp+abs(x[j]-temp);
   if temp<ans then ans:=temp;
  end;
  writeln (ans);
 end;


 close(input);
 close(output);
end.
