program D;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s, s1 : string;
    i, k, j : integer;

begin
 assign (input,'destroy.in');
 assign (output,'destroy.out');
 reset(input);
 rewrite(output);

 readln (k);
 readln (s);
 j:=1;
 while j<k do
 begin
  for i:=1 to length(s) do
  begin
   if ((i mod (j+1)) <>0) then s1:=s1+s[i];
  end;
  s:=s1;
  s1:='';
  inc (j);
 end;

 writeln (s);

 close(input);
 close(output);
end.
