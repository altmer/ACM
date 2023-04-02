program chess;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var s : string;
    i, k : integer;
    up: boolean;

Begin
  assign (input,'b.in');
  assign (output,'b.out');
  reset(input);
  rewrite(output);
  i:=0;
  while not seekeof do
  begin
   readln(s);
   if i<>0 then writeln;
   for i:=1 to length (s) do
   if (s[i]='.') or (s[i]='!') or (s[i]='?') then
   begin
    if (s[i+1]=' ') or (s[i+1]=' ') or (s[i+1]='(') or (s[i+1]=')') or (i+1>length(s)) then
    up:=true;
    write(s[i]);
   end

   else if (up=true) and (((ord(s[i])>=65) and (ord(s[i])<=90)) or ((ord(s[i])>=97) and (ord(s[i])<=122))) then
   begin
    write(upcase(s[i]));
    up:=false;
   end

   else if ((ord(s[i])>=65) and (ord(s[i])<=90)) or ((ord(s[i])>=97) and (ord(s[i])<=122)) then
    write (lowercase(s[i]))

   else write(s[i]);

  end;

  close(input);
  close(output);
end.
