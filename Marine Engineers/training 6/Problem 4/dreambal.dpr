program dreambal;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var 
  t, v, a, k,s : real;
Begin
  assign (input,'dreambal.in');
  assign (output,'dreambal.out');
  reset(input);
  rewrite(output);

  readln (v, a, k);
  a:=a*3.1415926535/180;

  repeat

  t:=2*v*sin(a)/10;
  s:=s+v*cos(a)*t;
  v:=v/sqrt(k);

  until v < 0.0000001;

  writeln (s : 4 :2);
  close(input);
  close(output);
end.
