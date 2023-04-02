program Project2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var i,m,d,a,c,e:integer;

begin
  assign(input,'factor.in');
  reset (input);
  assign(output,'factor.out');
  rewrite(output);
  read (a);
  i:=2;
  e:=trunc(sqrt(a))+1;
  c:=0;
  d:=a;
  m:=0;
  while i<=e  do
     begin
      if (a mod i)=0 then
       begin
        m:=m+1;
        a:=a div i;
        if i<>c then
          begin
          write (i,' ');
          c:=i;
          end;
       end
      else i:=i+1;
     end;
    if (i=e) and (m=0) then write(d) else

if (a<>1) then write(a);

  close(input);
  close(output);
end.
 