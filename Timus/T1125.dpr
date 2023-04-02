program T1125;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var clas : array [1..50, 1..50] of char;
    a : array [1..50, 1..50] of integer;
    n, m, i, j, num, k : integer;
dx:array [1..52] of integer=(3,4, 5,6, 7,8, 8, 9, 9,10,12,12,12,12,14,15,15,15,16,16,18,20,20,20,21,21,24,24,24,24,24,27,28,28,30,30,32,33,35,36,36,36,40,40,40,42,44,45,45,48,48,48);
dy:array [1..52] of integer=(4,3,12,8,24,6,15,12,40,24,5,9,16,35,48,8,20,36,12,30,24,15,21,48,20,28,7,10,18,32,45,36,21,45,16,40,24,44,12,15,27,48,9,30,42,40,33,24,28,14,20,36);

procedure revers (var a : char);

begin
 if a='W' then a:='B' else a:='W';
end; 

begin
 assign (input,'T1125.in');
 reset (input);
 assign (output,'T1125.out');
 rewrite(output);

 readln (m,n);

 for i:=1 to m do
 begin
  for j:=1 to n do read (clas[i,j]);
  readln;
 end;

 for i:=1 to m do
 begin
  for j:=1 to n do
  begin
   read (num);
   a[i,j]:=num mod 2;
  end;
  readln;
 end;

 for i:=1 to m do
  for j:=1 to n do
   if a[i,j]=1 then
   begin
    a[i,j]:=0;
    for k:=1 to m do revers (clas[k,j]);
    for k:=1 to n do revers (clas[i,k]);
    revers(clas[i,j]);
    k:=1;
    while k<=52 do
    begin
     if (i+dx[k]>=1) and (i+dx[k]<=m) and (j+dy[k]>=1) and (j+dy[k]<=n) then
      revers (clas[i+dx[k],j+dy[k]]);
     if (i-dx[k]>=1) and (i-dx[k]<=m) and (j-dy[k]>=1) and (j-dy[k]<=n) then
      revers (clas[i-dx[k],j-dy[k]]);
     if (i+dx[k]>=1) and (i+dx[k]<=m) and (j-dy[k]>=1) and (j-dy[k]<=n) then
      revers (clas[i+dx[k],j-dy[k]]);
     if (i-dx[k]>=1) and (i-dx[k]<=m) and (j+dy[k]>=1) and (j+dy[k]<=n) then
      revers (clas[i-dx[k],j+dy[k]]);
     inc(k);
    end;
   end;

 for i:=1 to m do
 begin
  for j:=1 to n do write (clas[i,j]);
  writeln;
 end;

 
 close (input);
 close (output);
end.



