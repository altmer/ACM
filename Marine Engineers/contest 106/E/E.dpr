program E;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var s : string;
    rank : array [1..6] of char = ('k', 'q', 'r', 'b', 'n', 'p');
    i, k : integer;
    j : char;
    grid : array [1..8, 'a'..'h'] of char;
    wh : boolean;

begin
 assign (input,'E.in');
 assign (output,'E.out');
 reset(input);
 rewrite(output);

 readln (s);
 i:=8;
 while i<length(s) do
 begin
  if (s[i]>'A') and (s[i]<'Z')then
  begin
   for k:=1 to 6 do
    if s[i] = upcase(rank[k]) then
     begin
      grid [strtoint(copy(s,i+2, 1 )), s[i+1]] := upcase(rank[k]);
      i:=i+4;
     end;
  end

  else
  begin
   grid [strtoint(copy(s, i+1, 1)), s[i]] := 'P';
   i:=i+3;
  end;
 end;

 readln (s);
 i:=8;
 while i<length(s) do
 begin
  if (s[i]>'A') and (s[i]<'Z')then
  begin
   for k:=1 to 6  do
    if s[i] = upcase(rank[k]) then
     begin
      grid [strtoint(copy(s,i+2, 1)), s[i+1]] := rank[k];
      i:=i+4;
     end;
  end

  else
  begin
   grid [strtoint(copy(s, i+1, 1)), s[i]] := 'p';
   i:=i+3;
  end;
 end;

 for i:=8 downto 1 do
 begin
  writeln ('+---+---+---+---+---+---+---+---+');
  if i mod 2 = 0 then wh:=true else wh:=false;
  write('|');
  for j:='a' to 'h' do
  begin
   if grid[i, j] <> #0 then

   begin
    if wh then write('.', grid[i,j], '.|')
     else write(':', grid[i,j], ':|');
   end
   else
   begin
    if wh then write('...|')
     else write(':::|');
   end;
   wh:=not wh;
  end;
  writeln;
 end;
 write ('+---+---+---+---+---+---+---+---+');

 close(input);
 close(output);
end.
