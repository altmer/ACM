program T1197;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var dx : array [1..8] of integer = (2,  2, 1,  1, -2, -2, -1, -1);
    dy : array [1..8] of integer = (-1, 1, 2, -2, -1,  1, -2,  2);
    n, i, j, u, v, k, l, ans : integer;
    s : string;    

begin
 assign (input,'T1197.in');
 reset (input);
 assign (output,'T1197.out');
 rewrite(output);

 readln (n);

 for k:=1 to n do
 begin
  readln (s);
  ans:=0;
  i:=ord(s[1])-ord('a')+1;
  j:=ord(s[2])-ord('0');
  for l:=1 to 8 do
  begin
   u:=i+dx[l];
   v:=j+dy[l];
   if (u>0) and (u<=8) and (v>0) and (v<=8) then inc (ans);   
  end;
  writeln (ans);
 end;
 
 close (input);
 close (output);
end.



