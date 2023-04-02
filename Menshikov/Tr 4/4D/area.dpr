program area;
{$APPTYPE CONSOLE}
uses
  SysUtils;

type point = record
      x, y : integer;
     end;

var n, i : integer;
    poly : array [1..50000] of point;
    s : real;

begin
 assign(input,'area.in');
 reset (input);
 assign(output,'area.out');
 rewrite(output);

 readln (n);
 for i:=1 to n do readln (poly[i].x, poly[i].y);

 s:=0;
 for i:=2 to n do
  s:=s+(poly[i-1].x-poly[i].x)*(poly[i-1].y+poly[i].y);

 s:=abs(s+(poly[n].x-poly[1].x)*(poly[n].y+poly[1].y))/2;
 writeln (s :0 : 1);
 close(input);
 close(output);
end.
