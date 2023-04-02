program Calendar;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var st, en : array [1..30] of integer;
    n, i, j, step, ToF, rev : integer;
    ans : array [1..52] of integer;

procedure revers (k : integer);
var i, t : integer;

begin
 for i:=1 to (k div 2) do
 begin
  t:=st[i];
  st[i]:=st[k-i+1];
  st[k-i+1]:=t;
 end;
end;

begin
 assign (input,'input.txt');
 assign (output,'output.txt');
 reset(input);
 rewrite(output);
 n:=1;
 while n<>0 do
 begin
  readln (n);
  for i:=1 to n do read (st[i]);
  readln;
  for i:=1 to n do read (en[i]);
  step:=1;

  for j:=n downto 1 do
  begin
   ToF := en[j];

   for i:=1 to n do
    if st[i]=ToF then
    begin
     if (i<>j) and (i<>1) then
      rev:=i
     else if (i<>j) then rev:=1
     else rev:=0;

     if (rev<>0) and (rev<>1) then
     begin
      ans [step]:=rev;
      inc(step);
      revers (rev);
      ans[step]:=j;
      revers(j);
      inc (step);
     end

     else if (rev=1) then
     begin
      ans[step]:=j;
      revers(j);
      inc (step);
     end;
     break;
    end;
   end;

  for i:=1 to step-1 do write (ans[i], ' ');
  writeln;
 end;
 
 close(input);
 close(output);
end.
