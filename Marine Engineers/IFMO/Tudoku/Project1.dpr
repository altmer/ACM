program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i, j : integer;

function WhichBlock (i, j : byte) : byte;
var s : integer;

begin
 s:=i div 3 + j div 3;
 case s of

 0: WhichBlock:=1;

 1: if i>2 then WhichBlock:=4 else WhichBlock:=2;

 2: if i<3 then WhichBlock:=3 else if i>5 then WhichBlock:=7 else WhichBlock:=5;

 3: if i>5 then WhichBlock:=8 else WhichBlock:=6;

 4: WhichBlock:=9;
 end;
end;

begin
 for i:=0 to 8 do
 begin
  for j:=0 to 8 do write(WhichBlock (i,j));
  writeln;
 end;

 readln(i);
end.
