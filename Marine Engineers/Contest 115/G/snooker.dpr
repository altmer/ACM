program Bb;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var  ball: array[1..7] of integer;
     i, ans, sum, max  : integer;
     color : string;
begin
 assign (input, 'snooker.in');
 assign (output, 'snooker.out');
 rewrite (output);
 reset (input);
 for i:=1 to 7 do read(ball[i]);
 readln; readln(color);
 ans:= 0; sum:=0;

 for i:=2 to 7 do if ball[i]<>0 then max:=i;

 for i:=2 to 7 do sum:=sum+ball[i]*i;
 if color = 'RED' then
  begin
   ans:=ball[1]+max+ball[1]*max+sum;
  end
 else
  begin
   ans:=ball[1]+ball[1]*max+sum;
  end;

 writeln(ans);
 close (input);
 close (output);
end.
