program cityblock;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n, m, rem, i : integer;
    k, res, ans : real;

Begin
  assign (input,'cityblock.in');
  assign (output,'cityblock.out');
  reset(input);
  rewrite(output);

  readln (n, m);
  n:=n-1; m:=m-1;
  if m>=n then  k:=m/n else begin k:=n/m; n:=m; end;

  for i:=1 to n do
  begin
   res:=res+k;
   if frac(res)>0.00001 then ans:=ans+trunc(res)+1 else ans:=ans+res;

   res:=frac(res);
  end;

  writeln (round(ans));

  close(input);
  close(output);
end.
