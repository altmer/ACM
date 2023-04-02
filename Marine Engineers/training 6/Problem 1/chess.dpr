program chess;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
 point = record
  x, y : integer;
  end;

var a : array[1..8, 1..8] of integer;
    n, i, j : integer;
    st : point;
    dx : array [1..8] of integer = (2,  2, -2, -2, 1,  1, -1, -1);
    dy : array [1..8] of integer = (1, -1,  1, -1, 2, -2,  2, -2);
    err : boolean = false; 

Begin
  assign (input,'chess.in');
  assign (output,'chess.out');
  reset(input);
  rewrite(output);

  readln (n);
  for i:=1 to n do
  begin
   for j:=1 to n do
   begin
    read (a[i,j]);
    if a[i,j] = 1 then
    begin
     st.x := i;
     st.y := j;
    end;
   end;
   readln;
  end;

  for i:=2 to n*n do
  begin

   for j:=1 to 8 do
   begin
    if a[st.x+dx[j], st.y+dy[j]] = i then
    begin
     err:=false;
     st.x:=st.x+dx[j];
     st.y:=st.y+dy[j];
     break;
    end

    else err:=true;
   end;
   if err=true then
   begin
    writeln ('Error');
    halt;
   end;
  end;

  writeln ('Congratulation');

  close(input);
  close(output);
end.
