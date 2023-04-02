program Project1;

{$APPTYPE CONSOLE}

var m, i :integer;
    head, tail : integer;
    max : integer = 0;
    k : array [1..25001] of integer;

function findmax (l,r : integer) : integer;
var i : integer;

begin
 max:=0;
 for i:=head to tail do if k[i]>max then max:=k[i];
 findmax:=max;
end;

begin
 assign (input,'telefon.in');
 assign (output,'telefon.out');
 reset(input);
 rewrite(output);
  head:=1;
  readln(m);

  for tail:=1 to m do
  begin
   readln (k[tail]);
   if k[tail]>max then max:=k[tail];
  end;

  writeln (max);
  readln (k[tail]);

  while k[tail]<>-1 do
  begin
   if k[head] = max then
   begin
    inc (head);
    max := FindMax (head, tail);
   end

   else
   begin
    inc (head);
    if k[tail]>max then max:=k[tail];
   end;
   writeln(max);
   inc (tail);
   readln (k[tail]);
  end;
  close(input);
  close(output);
 
end.
