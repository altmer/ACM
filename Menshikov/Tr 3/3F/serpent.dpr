program serpent;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const max=100;

var a : array [1..max,1..max] of integer;
    n, m , i, j, sti, stj : integer;

begin
 assign (input,'serpent.in');
 reset (input);
 assign (output,'serpent.out');
 rewrite(output);

 readln (n);
 if n=1 then
 begin
  writeln ('1');
  halt
 end;
 a[1,n]:=1;
 a[n,1]:=sqr(n);
 m:=2;
 sti:=1; stj:=n-1; 

 repeat
  i:=sti; j:=stj;
  while (i<n) and (j<n) do
   begin
    a[i,j]:=m;
    inc(i);
    inc(j);
    inc(m);
   end;

   if (j=n) and (i=n) then
   begin
    a[i,j]:=m;
    inc(m);
    inc(sti);
   end

   else if j=n then
   begin
    a[i,j]:=m;
    inc(m);
    dec (stj);
   end

   else if i=n then
   begin
    a[i,j]:=m;
    inc(m);
    inc (sti);
   end;
  until m>=sqr(n);

 for i:=1 to n do
 begin
  for j:=1 to n do write (a[i,j], ' ');
  writeln;
 end;

 close (input);
 close (output);
end.
