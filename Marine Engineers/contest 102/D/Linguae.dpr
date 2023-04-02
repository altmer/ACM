program barrel;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var q : array [1..10000] of byte;
    head, tail : integer;
    scen, n, k : integer;
    a : array[0..100,0..100] of byte;


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

  readln (n);
  for i:=0 to n-1 do
  begin
   for j:=1 to 3 do
   begin
    if i+j>n then
     if a[i,j+i]<>0 then
     begin
      read (a[i,j+i])
     end;
     else read (a[i,n]);
   end;
  end;
   readln;



















  end;

  close(input);
  close(output);
end.
