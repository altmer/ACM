program chess;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var adis, edis : integer;
    c : char;
    a, b : array [1..10] of real; 
    i, k, l : integer;

function speed1 (a : array of real; dis : real) : real;
var i : integer;
    time : real;

begin
 for i:=0 to 9 do time:=time+a[i];
 dis:=10*dis;
 speed1:=dis/time;
end;

function speed2 (a : array of real; dis : real) : real;
var i : integer;
    speed : real;

begin
 for i:=0 to 9 do
  speed:=speed + dis/a[i];
 speed2:=speed/10;
end;


Begin
  assign (input,'a.in');
  assign (output,'a.out');
  reset(input);
  rewrite(output);

  readln (adis, edis);
  k:=1;
  l:=1;
  for i:=1 to 20 do
  begin
   read (c);

   if (c='a') or (c='A') then
   begin
    read (a[k]);
    inc(k);
   end
   else
   begin
    read (b[l]);
    inc(l);
   end;
   readln;
  end;

  writeln('Method 1');
  writeln ('African: ', speed1(a, adis) : 4 : 2, ' furlongs per hour');
  writeln ('European: ', speed1(b, edis) : 4 : 2, ' furlongs per hour');
  writeln('Method 2');
  writeln ('African: ', speed2(a, adis) : 4 : 2, ' furlongs per hour');
  writeln ('European: ', speed2(b, edis) : 4 : 2, ' furlongs per hour');

  close(input);
  close(output);
end.
