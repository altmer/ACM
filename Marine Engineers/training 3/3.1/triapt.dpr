program triapt;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var x, y : array [1..4] of integer;
    k, b, l : array[1..3] of real;
    i, dr, ur, pr : integer;
    res : boolean;
label 1;

begin
  assign (input,'tria-pt.in');
  assign (output,'tria-pt.out');
  reset(input);
  rewrite(output);
  for i:=1 to 4 do readln (x[i], y[i]);
  dr:=1;
  ur:=1;
  for i:=1 to 3 do
   begin
    if y[i] > y[ur] then ur:=i else if (x[i]>x[ur]) and (y[i]=y[dr]) then ur:=i;
    if y[i] < y[dr] then dr:=i else if (x[i]>x[ur]) and (y[i]=y[ur]) then dr:=i;
   end;

   pr:=6 - dr - ur;
      {1-я прямая}
   if x[dr]=x[ur] then
   begin
    l[1]:=0;
    k[1]:=1;
    b[1]:=-x[dr];
   end
    else
   begin
    k[1]:=(y[dr]-y[ur])/(x[dr]-x[ur]);
    l[1]:=1;
    b[1]:=y[ur]-x[ur]*(y[dr]-y[ur])/(x[dr]-x[ur]);
   end;
      {2-я прямая}
   if x[pr]=x[dr] then
   begin
    l[2]:=0;
    k[2]:=1;
    b[2]:=-x[dr];
   end
    else
    begin
     k[2]:=(y[pr]-y[dr])/(x[pr]-x[dr]);
     l[2]:=1;
     b[2]:=y[dr]-x[dr]*(y[pr]-y[dr])/(x[pr]-x[dr]);
    end;
      {3-я прямая}
   if x[pr]=x[ur] then
   begin
    l[3]:=0;
    k[3]:=1;
    b[3]:=-x[pr];
   end
   else
    begin
     k[3]:=(y[ur]-y[pr])/(x[ur]-x[pr]);
     l[3]:=1;
     b[3]:=y[pr]-x[pr]*(y[ur]-y[pr])/(x[ur]-x[pr]);
    end;


  if ( (l[1]*y[pr] < (k[1]*x[pr]+b[1])) and (l[1]*y[4]<=(k[1]*x[4]+b[1])) ) or
     ( (l[1]*y[pr] > (k[1]*x[pr]+b[1])) and (l[1]*y[4]>=(k[1]*x[4]+b[1])) )
     then res := true else
     begin
      res:=false;
      goto 1;
     end;

  if ( (l[2]*y[ur] < (k[2]*x[ur]+b[2])) and (l[2]*y[4]<=(k[2]*x[4]+b[2])) ) or
     ( (l[2]*y[ur] > (k[2]*x[ur]+b[2])) and (l[2]*y[4]>=(k[2]*x[4]+b[2])) )
     then res := true else
     begin
      res:=false;
      goto 1;
     end;

   if ( (l[3]*y[dr] < (k[3]*x[dr]+b[3])) and (l[3]*y[4]<=(k[3]*x[4]+b[3])) ) or
     ( (l[3]*y[dr] > (k[3]*x[dr]+b[3])) and (l[3]*y[4]>=(k[3]*x[4]+b[3])) )
     then res := true else
     begin
      res:=false;
      goto 1;
     end;

1:if res = true then write ('In') else write ('Out');


  close(input);
  close(output);
end.
