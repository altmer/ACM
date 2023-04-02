program square;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [1..102500] of integer;
    i:integer;

begin
  assign (input,'6.in');
  assign (output,'6.out');
  reset(input);
  rewrite(output);
  i:=1;
  while not seekeof do
  begin
   read (a[i]);
   i:=i+1;
  end;

  for i:=i-1 downto 1 do writeln (sqrt(a[i]) : 3 : 4);

  close(input);
  close(output);
end.
