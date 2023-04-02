program factor_pre;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var i, k, count : integer;
    res : boolean; 

begin
  assign(output,'factor.txt');
  rewrite(output);

  count:=0;
  i:=2;
  while i<=47000 do
  begin
   res:=true;
   for k:=2 to round(sqrt(i)) do
   begin
    if (k<>i) and ((i mod k)=0) then
    begin
     res:=false;
     break;
    end;
   end;
   if res then
   begin
    write (i, ', ');
    inc (count);
   end;
   inc(i);
  end;
  writeln;
  writeln;
  writeln (count);

  close(output);
end.
