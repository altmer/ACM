program barrel;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
 location = record
  x, y : byte;
  end;

var q : array [1..10000] of byte;
    head, tail : integer;
    scen, n, k : integer;
    a : array[1..100, 1..100] of byte;
    

procedure push (u : location);

begin
 q[tail]:=u;
 inc(tail);
end;

function take : location;

begin
 take:=q[head];
 inc (head);
end;

function IsEmpty : boolean;

begin
 IsEmpty:=(head=tail);
end;





Begin
  assign (input,'hike.in');
  assign (output,'hike.out');
  reset(input);
  rewrite(output);

  readln (scen);
  for k:=1 to scen do
  begin
   readln (n);
   for i:=1 to n do
   begin
    for j:=1 to n do read (a[i,j]);
    readln;
   end;


















  end;

  close(input);
  close(output);
end.
