program E;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type date = record
      m, d, h, min : integer;
      sign : char;
      end;

var n : integer = 1;
    i, ans : integer;
    d1, d2, dps, dpe : date;
    s : array [1..1000] of string;
    StCount : boolean;

function IsSameYear (d1, d2 : date) : boolean;
var res : boolean;

begin
 if d2.m<d1.m then res:=true
  else if d2.m=d1.m then
  begin
   if d2.d<d1.d then res:=true
    else if d2.d=d1.d then
    begin
     if d2.h<d1.h then res:=true
     else if d2.h=d1.h then
     begin
      if d2.min<d1.min then res:=true
       else res:=false;
     end
     else res:=false;
    end
    else res:=false;
  end
  else res:=false;
  IsSameYear:=res;
end;


begin
 assign (input,'E.in');
 assign (output,'E.out');
 reset(input);
 rewrite(output);

 while n<>0 do
 begin
  StCount:=false;
  readln (n);
  ans:=0;
  for i:=1 to n do
   readln (s[i]);
  d1.m:=strtoint (copy(s[1], 1, 2));
  d1.d:=strtoint (copy(s[1], 4, 2));
  d1.h:=strtoint (copy(s[1], 7, 2));
  d1.min:=strtoint (copy(s[1], 10, 2));
  d1.sign:=(s[1, length(s[1])]);
  if d1.sign='+' then
  begin
   inc(ans);
   stcount:=true;
   dps:=d1;
   dpe:=dps;
  end;
  for i:=2 to n do
  begin
   d2.m:=strtoint (copy(s[i], 1, 2));
   d2.d:=strtoint (copy(s[i], 4, 2));
   d2.h:=strtoint (copy(s[i], 7, 2));
   d2.min:=strtoint (copy(s[i], 10, 2));
   d2.sign:=(s[i, length(s[i])]);

   if IsSameYear (d2, d1) then
   begin
    if d2.sign='+' then
    begin
     if (StCount) and (not IsSameYear (d2, dpe)) and (dpe.sign='-') then
      dec(ans);
     if (stCount) and (IsSameYear (d2, dps)) then inc(ans);
     StCount:=true;
     inc (ans);
     dps:=d2;
    end;
   end
   else
   begin
    dpe:=d1;
    dps:=d2;
    if StCount then inc(ans);
   end;

   d1:=d2;
  end;
  if n<>0 then writeln (ans);
 end;
 

 close(input);
 close(output);
end.
