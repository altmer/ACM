program rout;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
 initial = 10;
 left = 11;
 up = 12;
 route = 13;  

var a : array [1..250,1..250] of byte;
    m : array [1..250, 1..250] of byte;
    i,j,n : integer;
    c : char;

begin
 assign (input,'route.in');
 reset (input);
 assign (output,'route.out');
 rewrite(output);

 readln (n);
 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   read (c);
   a[i,j]:=ord(c)-ord('0');
  end;
  readln;
 end;


 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   if (i=1) and (j=1) then
   begin
    m[i,j]:=a[1,1];
    a[i,j]:=initial;
   end

   else if i=1 then
   begin
    m[i,j]:=m[i,j-1]+a[i,j];
    a[i,j]:=left;
   end

   else if j=1 then
   begin
    m[i,j]:=m[i-1,j]+a[i,j];
    a[i,j]:=up;
   end

   else
   begin
    if m[i-1, j]< m[i,j-1] then
    begin
     m[i,j]:=m[i-1, j]+a[i,j];
     a[i,j]:=up;
    end
    else
    begin
     m[i,j]:=m[i, j-1]+a[i,j];
     a[i,j]:=left;
    end
   end;
  end;
 end;

 i:=n;
 j:=n;

 while a[i, j] <> initial do
 begin
  if a[i, j]=left then
  begin
   a[i,j]:=route;
   dec(j);
  end
  else
  begin
   a[i,j]:=route;
   dec(i);
  end;
 end;

 a[1,1]:=route;

 for i:=1 to n do
 begin
  for j:=1 to n do
   if a[i,j]=route then write ('#') else write ('-');
  writeln;
 end;



 close (input);
 close (output);
end.
