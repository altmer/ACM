program T1084;
{$apptype console}

uses
  sysutils;

const p =  3.141592653589793238462643383279502884197169399375;

var r, a : integer;
    alpha, sinus : extended;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1084.in');
 reset(input);
 assign(output, 'T1084.out');
 rewrite(output);
{$ENDIF}

 readln (a, r);

 if r<=a/2 then write (p*r*r : 0 : 3)

 else if r>=sqrt(2)*a/2 then

 begin
  sinus:=a*a;
  write (sinus:0:3)
 end

 else
 begin
  while ((r*cos(alpha))>(a/2)) do alpha:=alpha+0.0000001;
  write ((p*r*r-4*((2*alpha*r*r-sin(2*alpha)*r*r)/2)) : 0 : 3);
 end;

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
