program postcard;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const eps = 1e-10;  

var Ho, Wo, Hk, Wk, t : integer;
    AC, CF,BAE, GE : extended;

begin
 assign (input,'postcard.in');
 reset (input);
 assign (output,'postcard.out');
 rewrite(output);

 readln (Ho, Wo, Hk,Wk);
 if Ho>Wo then
 begin
  t:=Wo;
  Wo:=Ho;
  Ho:=t;
 end;
 if Hk>Wk then
 begin
  t:=Wk;
  Wk:=Hk;
  Hk:=t;
 end;

 if Ho>Hk then writeln ('Impossible')

 else if Wo<=Wk then writeln ('Possible')

 else
 begin
  AC:=sqrt (Ho*Ho+Wo*Wo);
  CF:=sqrt (AC*AC-Hk*Hk);
  BAE:=pi/2-(arctan(Ho/Wo)+arctan(CF/Hk));
  GE:=Ho*sin(BAE)+Wo*cos(BAE);
  if GE<=WK+eps then writeln ('Possible') else writeln ('Impossible');
 end;


 close (input);
 close (output);
end.
