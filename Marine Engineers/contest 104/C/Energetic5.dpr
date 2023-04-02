program Energetic5;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type coord = record
      x, y : integer;
      end;

var O, L1, L2, ACC,T, C : coord;
    ca1, ca2, sa1, sa2, c1x, c2x, s1x, s2x, cax, cay, cbx, cby : real;
    rel, l, sin12, a, b : real;

function coss(a1,a2,a3,a4:coord): real;
begin
coss:=((a1.x-a2.x)*(a3.x-a4.x) + (a1.y-a2.y)*(a3.y-a4.y))/( sqrt(sqr(a1.x-a2.x)+sqr(a1.y-a2.y))*
  sqrt(sqr(a3.x-a4.x)+sqr(a3.y-a4.y)));
end;

begin
 assign (input,'energy.in');
 assign (output,'energy.out');
 reset(input);
 rewrite(output);
 T.y:=0; t.x:=1;
 c.x:=0; c.y:=0;
 readln (O.x, O.y, L1.x, L1.y, L2.x, L2.y);
 readln (ACC.x, ACC.y);

 ca1 :=coss(L1,O,ACC,O);
 ca2 :=coss(L2,O,ACC,O);

 sa1 := sqrt (1 - sqr (ca1));
 sa2 := sqrt (1 - sqr (ca2));

 rel:=sa1/sa2 ;
  //’¿’¿’¿ - ¬≈–ÕŒ!
 l:=sqrt(sqr(acc.x-o.x)+sqr(acc.y-o.y));
 sin12:=sa2*ca1+sa1*ca2;
 a:=(l*sa1+rel*l*sa2)/(rel*sin12);
 b:=a*rel;

 c1x := coss (L1, O, T, C);
 c2x := coss (L2, O, T, C);
 s1x := sqrt (1 - sqr (c1x));
 s2x := sqrt (1 - sqr (c2x));

 cax := a*c1x+O.x;
 cay := a*s1x+O.y;
 cbx := b*c2x+O.x;
 cby := b*s2x+O.y;

 writeln (cax : 0 : 9, ' ', cay : 0 : 9, ' ', cbx : 0 : 9, ' ', cby : 0 : 9);

 close(input);
 close(output);
end.
