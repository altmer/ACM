program A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var k1, k2, k3 : extended;
    sum : extended;

begin
 assign (input, 'input.txt');
 assign (output, 'output.txt');
 reset (input);
 rewrite (output);

 readln (k1, k2, k3);
 sum:=k2*1000/(1+k2/k1+k2/k3);
 
 writeln (round(sum));

 

 close (input);
 close (output);
end.
