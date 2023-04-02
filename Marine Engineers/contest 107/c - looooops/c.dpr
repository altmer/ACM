program c;

{$APPTYPE CONSOLE}

uses SysUtils;

var   t,B,S,K,L,Z,n,ans:integer;
      temp: array [0..10000] of boolean;

begin
 assign (input,'c.in');
 assign (output,'c.out');
 reset(input);
 rewrite(output);

 ans:=0;
 readln(t,B,S,K);
 n:=round(exp(k*ln(2)));
 L:=n div S;
 Z:=n mod S;
  while  1>0 do
  begin
   if  (((b-t) mod S)=0)   then
    begin
     writeln(ans+((b-t) div S));
     break;
     end
    else
   t:=L*S+Z+t-n;
   if temp[t]=true then
    begin
    writeln('FOREVER');
    break;
    end
   else temp[t]:=true;
   ans:=ans+L;
  end;



 close(input);
 close(output);
end.
