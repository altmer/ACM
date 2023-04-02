program linguae;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [1..1000,1..1000] of integer;
    res : boolean;
    i,j,n : integer;

Begin
  assign (input,'h.in');
  assign (output,'h.out');
  reset(input);
  rewrite(output);

  while not seekeof do
  begin
    res:=false;
    readln(n);
  if n<>0 then
  begin
    for i:=1 to n do
    for j:=1 to n do read(a[i,j]);

    for i:=1 to n-1 do
    begin
     if res then break;
     for j:=2 to n do
      if (a[i+1,j]-a[i,j] = a[i+1, j-1] - a[i, j-1]) then res:=false
       else
        begin
         res:=true;
         break;
        end;
     end;

    if not res then
    for i:=1 to n-1 do
    begin
     if res then break;
     for j:=2 to n do
      if (a[j,i+1]-a[j,i] = a[j-1, i+1] - a[j-1, i]) then res:=false
       else
        begin
         res:=true;
         break;
        end;
      end;

    if not res then writeln ('homogeneous') else writeln ('not homogeneous');
    end;
  end;
  close(input);
  close(output);
end.
