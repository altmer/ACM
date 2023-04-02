program Bb;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, k1,k2,p1,p2,p3, ans :integer;
    
begin
 assign (input, 'billing.in');
 assign (output, 'billing.out');
 rewrite (output);
 reset (input);

 readln(n, k1, k2, p1, p2 ,p3);

  ans:=0;

 if n<p1 then ans:=0 else
 begin
  ans:=ans+k1;
  n:=n-p1;
  while (n>0) and (k2>0) do
   begin
    inc(ans);
    dec(k2);
    n:=n-p2;
   end;
  while n>0 do
   begin
    inc(ans);
    n:=n-p3;
   end;
 end;

   write(ans1);
 close (input);
 close (output);
end.
