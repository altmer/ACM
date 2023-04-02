program T1070;
{$apptype console}

uses
  sysutils;

type time = record
      h, m : integer;
      sign : boolean;
     end;

var a, b : real;
    t1, t2, t3, t4, dif1, dif2, dif3 : time;

function dif (t2, t1  :time) : time;
var corh : integer;

begin
 corh:=0;
 if t2.m<t1.m then
 begin
  corh:=-1;
  dif.m:=t2.m+60-t1.m;  
 end
 
 else dif.m:=t2.m-t1.m;

 if t2.h<t1.h then
  dif.h:=corh+t2.h+24-t1.h
   else dif.h:=corh+t2.h-t1.h;
end;

function add (t1, t2 : time) : time;
var carry, hour : integer;

begin
 carry:=t1.m+t2.m;
 add.m:=carry mod 60;
 carry:=carry div 60;
 hour:=carry+t1.h+t2.h;
 add.h:=hour;
end;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1070.in');
 reset(input);
 assign(output, 'T1070.out');
 rewrite(output);
{$ENDIF}

 readln (a, b);

 t1.h:=trunc(a);
 t1.m:=round(frac(a)*100);
 t2.h:=trunc(b);
 t2.m:=round(frac(b)*100);
 readln (a, b);
 t3.h:=trunc(a);
 t3.m:=round(frac(a)*100);
 t4.h:=trunc(b);
 t4.m:=round(frac(b)*100);

 dif1:=dif(t2, t1);
 dif1.sign:=false;
 if dif1.h>=11 then
 begin
  dif1:=dif(t1, t2);
  dif1.sign:=true;
 end;

 dif2:=dif(t4, t3);
 dif2.sign:=false;
 if dif2.h>=11 then
 begin
  dif2:=dif(t3, t4);
  dif2.sign:=true;
 end;

 if (dif1.sign) or (dif2.sign) then
 begin
  dif3:=add(dif1, dif2);
 end

 else
 begin
  if dif2.h>dif1.h then dif3:=dif(dif2, dif1)

  else if dif2.h=dif1.h then
  begin
   if dif2.m>dif1.m then dif3:=dif(dif2, dif1)
    else dif3:=dif(dif1, dif2);
  end

  else dif3:=dif(dif1, dif2);
 end;

 if 60-dif3.m<=10 then inc(dif3.h);
 writeln (dif3.h div 2);

 



{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
