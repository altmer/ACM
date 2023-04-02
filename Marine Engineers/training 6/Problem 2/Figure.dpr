program Figure;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
 point = record
  x, y : integer;
  end;

var
 a : array [1..4] of point;
 cos13, cos24, cos12, cos34 : real;
 l1, l2 : real;
 i : integer;

Begin
  assign (input,'Figure.in');
  assign (output,'Figure.out');
  reset(input);
  rewrite(output);

  for i:=1 to 4 do readln (a[i].x, a[i].y);

  cos13 := (abs ((a[1].x-a[2].x)*(a[3].x-a[4].x)+(a[1].y-a[2].y)*(a[3].y-a[4].y)))/(sqrt(sqr(a[1].x-a[2].x)+sqr(a[1].y-a[2].y))*sqrt(sqr(a[3].x-a[4].x)+sqr(a[3].y-a[4].y)));
  cos24 := (abs ((a[3].x-a[2].x)*(a[1].x-a[4].x)+(a[3].y-a[2].y)*(a[1].y-a[4].y)))/(sqrt(sqr(a[3].x-a[2].x)+sqr(a[3].y-a[2].y))*sqrt(sqr(a[1].x-a[4].x)+sqr(a[1].y-a[4].y)));

  cos12 := (abs ((a[1].x-a[2].x)*(a[3].x-a[2].x)+(a[1].y-a[2].y)*(a[3].y-a[2].y)))/(sqrt(sqr(a[1].x-a[2].x)+sqr(a[1].y-a[2].y))*sqrt(sqr(a[3].x-a[2].x)+sqr(a[3].y-a[2].y)));
  cos34 := (abs ((a[3].x-a[4].x)*(a[1].x-a[4].x)+(a[3].y-a[4].y)*(a[1].y-a[4].y)))/(sqrt(sqr(a[3].x-a[4].x)+sqr(a[3].y-a[4].y))*sqrt(sqr(a[1].x-a[4].x)+sqr(a[1].y-a[4].y)));

  l1 := sqrt(sqr(a[1].x-a[2].x)+sqr(a[1].y-a[2].y));
  l2 := sqrt(sqr(a[3].x-a[2].x)+sqr(a[3].y-a[2].y));

  if (cos13= 1) and (cos24= 1)

  then
   begin
    if (cos12=0) and (cos34=0) then
    begin
     if l1 = l2 then
      writeln ('Square')
      else writeln ('Rectangle');
    end

    else writeln ('Parallelogram');
   end

  else if (cos13=1) or (cos24=1) then writeln ('Trapezium')

  else writeln ('Quadrangle');

  close(input);
  close(output);
end.
