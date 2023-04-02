program T1106;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type coord = record
      x, y : real;
      end;

var nail : array [1..100] of coord;
    rope, r : real;
    i, n : integer;

begin
 assign (input,'T1020.in');
 reset (input);
 assign (output,'T1020.out');
 rewrite(output);

 readln(n, r);

 for i:=1 to n do
 begin
  readln (nail[i].x, nail[i].y)
 end;

 for i:=1 to n-1 do
  rope:=rope+sqrt(sqr(nail[i+1].x-nail[i].x)+sqr(nail[i+1].y-nail[i].y));

 rope:=rope+2*pi*r+sqrt(sqr(nail[n].x-nail[1].x)+sqr(nail[n].y-nail[1].y));
 writeln (rope : 1 : 2);


 close (input);
 close (output);
end.



