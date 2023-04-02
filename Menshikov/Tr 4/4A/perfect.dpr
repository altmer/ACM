program perfect;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var m, n : integer;
    i : integer;
    k, sum : integer;
    res : boolean;

begin
 assign(input,'perfect.in');
 reset (input);
 assign(output,'perfect.out');
 rewrite(output);

 readln (m, n);
 if m=1 then inc(m);
 for i:=m to n do
 begin
  k:=2;
  sum:=0;
  while k<sqrt(i) do
  begin
   if i mod k = 0 then sum:=sum+k+(i div k);
   inc(k);
  end;
  inc(sum);
  if sum = i then
  begin
   writeln(i);
   res:=true;
  end;
 end;
 if not res then writeln('Absent');
 close(input);
 close(output);
end.
