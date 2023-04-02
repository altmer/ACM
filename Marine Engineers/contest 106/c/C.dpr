program H;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type point = record
     x, y, d, a : real;
     end;

     coord =record
      x,y: real;
     end;


var chain : array[0..10000] of point;
    i, j : integer;
    n, c, s : integer;
    b, sb, cb : real;
    index,temp: coord;
begin
 assign (input,'c.in');
 assign (output,'c.out');
 reset(input);
 rewrite(output);
while not seekEOF do
begin
 readln(n, c);
 for i:=1 to n do
 read(chain[i].d);
 readln;
 i:=1;
 j:=0;

 while i<=n do
 begin
 chain[i].y:=chain[i-1].y+chain[i].d;
 chain[i].x:=0;
 inc(i);
 end;

 while j<c do
 begin
 inc(j);
 readln(s, b);
 b:=pi*(-b)/180;
 index.x:=chain[s].x ; index.y:=chain[s].y ;
 sb:=sin(b);
 cb:=cos(b);
 for i:=s+1 to n do
  begin
   temp.y:=chain[i].y; temp.x:=chain[i].x;
   chain[i].x:=(temp.x-index.x)*cb-(temp.y-index.y)*sb+index.x;
   chain[i].y:=(temp.x-index.x)*sb+(temp.y-index.y)*cb+index.y;
  end;
  writeln(chain[n].x:0:2,' ', chain[n].y:0:2);
 end;
 readln;
 writeln;

end;

 close(input);
 close(output);
end.
