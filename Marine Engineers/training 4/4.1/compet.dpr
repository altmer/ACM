program compet;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a,b:array [0..10000] of integer;
    n,i,k,j:integer;


begin
  assign (input,'compet.in');
  assign (output,'compet.out');
  reset(input);
  rewrite(output);
  readln(n);
  i:=0;
  while (not seekeof) and (i<=n) do
  begin
  read (a[i]);
  i:=i+1;
  end;

  for i:=0 to (n-1) do
   begin
    k:=0; j:=0;
     while k<=n-1 do
      begin
       if a[k]>a[i] then
        j:=j+1;
       k:=k+1;
      end;
    b[i]:=j;
   end;
  j:=0;
  for i:=0 to (n-1) do
   if b[i]=0 then
    begin
     j:=j+1;
     write(i,' ');
    end;
  writeln;
  k:=j;
  for i:=0 to (n-1) do
   if b[i]=k then
    begin
     j:=j+1;
     write(i,' ');
    end;
  writeln;
  k:=j;
  for i:=0 to (n-1) do
   if b[i]=k then
    begin
     j:=j+1;
     write(i,' ');
    end;
  writeln;
  {for i:=0 to (n-1) do
  writeln (a[i],' ',b[i]);}



  close(input);
  close(output);
end.
