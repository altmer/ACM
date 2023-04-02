program hole;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type location = record
      x, y : integer;
      end;

var BL, TR : location;
    n, step, i, j, white, black : integer;
    a : array [0..100, 0..100] of boolean;

begin
 assign (input,'hole.in');
 assign (output,'hole.out');
 reset(input);
 rewrite(output);

 readln (n);
 // задание доски, подсчет кол-ва клеток
 black:=0;
 if odd(n) then
 begin
  step:=1;
  for i:=0 to n-1 do
  for j:=0 to n-1 do
   begin
    if odd(step) then
    begin
     a[i,j]:=true;
     inc (black);
    end;
    inc(step);
   end;
  end
  else
  begin
   for i:=0 to n-1 do
   begin
   if odd(i+1) then step:=1 else step:=2;
    for j:=0 to n-1 do
    begin
     if odd(step) then
     begin
      a[i,j]:=true;
      inc (black);
     end;
     inc(step);
    end;
   end;
  end;
 white:=n*n-black;

 readln (BL.x, BL.y, TR.x, TR.y);
 for i:=BL.y to TR.y do
 for j:=BL.x to TR.x do if a[i,j] then dec(black) else dec (white);

 writeln (abs(white-black));

 close(input);
 close(output);
end.
