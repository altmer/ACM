program T1493;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var  s : string;
     sum1, sum2, sum3, num, num1, num2 : integer;

begin
 assign (input,'T1493.in');
 reset (input);
 assign (output,'T1493.out');
 rewrite(output);

 readln (s);
 sum1:= ord(s[1])+ord(s[2])+ord(s[3])-3*ord('0');

 num:=100*(ord(s[4])-ord('0'))+10*(ord(s[5])-ord('0'))+(ord(s[6])-ord('0'));
 num1:=num+1;
 num2:=num-1;

 sum2:=0;
 sum3:=0;

 sum2:=sum2+num1 div 100;
 num1:=num1- 100*(num1 div 100);
 sum2:=sum2+num1 div 10;
 num1:=num1 - 10*(num1 div 10);
 sum2:=sum2 + num1;

 sum3:=sum3+num2 div 100;
 num2:=num2- 100*(num2 div 100);
 sum3:=sum3+num2 div 10;
 num2:=num2 - 10*(num2 div 10);
 sum3:=sum3 + num2;


 if (sum2=sum1) or (sum3=sum1) then writeln ('Yes') else writeln ('No');

 close (input);
 close (output);
end.



