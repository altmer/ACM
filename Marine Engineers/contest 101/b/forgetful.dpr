program barrel;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var s : string;
    n, i, j, ans : integer;
    k, l : integer;
    dx : array [1..8] of integer = (2,  2, -2, -2, 1,  1, -1, -1);
    dy : array [1..8] of integer = (1, -1,  1, -1, 2, -2,  2, -2);

Begin
 assign (input,'telefon.in');
 assign (output,'telefon.out');
 reset(input);
 rewrite(output);

 readln (n);
 for i:=1 to n do
 begin
  readln (s);
  k := ord(s[1])-ord('a')+1;
  l := ord(s[2])-ord('0');
  for j:=1 to 8 do
   if (k+dx[j]>=1)and(k+dx[j]<=8)and(l+dy[j]>=1)and(l+dy[j]<=8) then inc(ans);
  writeln (ans);
  ans:=0;
 end;

 close(input);
 close(output);
end.
