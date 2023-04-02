program T1313;
{$apptype console}

uses
  sysutils;

const max = 101;

var n, i, j, sti, stj : integer;
    a : array [0..101, 0..101] of integer;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1313.in');
 reset(input);
 assign(output, 'T1313.out');
 rewrite(output);
{$ENDIF}

 readln (n);
 for i:=0 to n+1 do
 begin
  a[i,0]:=max;
  a[i,n+1]:=max;
  a[0,i]:=max;
  a[0,n+1]:=max;
 end;

 for i:=1 to n do
 begin
  for j:=1 to n do read (a[i][j]);
  readln;
 end;

 write (a[1,1], ' ');
 sti := 2;
 stj := 1;
 if n<>1 then 
 repeat
  i:=sti;
  j:=stj;
  while a[i,j]<>max do
  begin
   write (a[i, j], ' ');
   dec(i);
   inc(j);
  end;
  if j>n then
   inc(stj)
    else inc(sti);
 until stj>n;

  
{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
