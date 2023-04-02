program linguae;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
  number = record
   one, wto, there : integer;
   end;


var a : array [1..100,1..100] of integer;
    res: array [1..100] of integer;


    i,j,n,letter,temp : integer;



Begin
  assign (input,'homogeneous.in');
  assign (output,'homogeneous.out');
  reset(input);
  rewrite(output);

while not eof do
begin
    readln(n);
    if n=0 then halt ;
    for i:=1 to n do
    for j:=1 to n do
     begin
     read(letter);
     a[i,j]:=letter;
    end;
    for i:=1 to n do






end;
  close(input);
  close(output);
end.
