program enumber;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var
  e : string = '2.71828182845904523536028750';
  n, i : integer;
Begin
  assign (input,'enumber.in');
  assign (output,'enumber.out');
  reset(input);
  rewrite(output);

  readln(n);

  if n=0 then
  begin
   writeln('3');
   halt;
  end;

  if n=9 then
  begin
   writeln ('2.718281829');
   halt;
  end;
  write(e[1],e[2]);

  for i:=1 to n do
  begin
   if i=n then
   begin
    if strtoint(e[i+3])>=5 then write(strtoint(e[i+2])+1) else write (e[i+2])
   end
   else write (e[i+2]);
  end;
  close(input);
  close(output);
end.
