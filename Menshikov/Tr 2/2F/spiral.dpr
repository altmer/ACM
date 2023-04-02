program compet;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a:array[1..100,1..100] of integer;
    n,j,i,way:integer;
    bar, st:array[1..4]of integer;








begin
  assign (input,'spiral.in');
  assign (output,'spiral.out');
  reset(input);
  rewrite(output);
  read(n);
  a[1,1]:=1;
  bar[1]:=n-1;
  bar[2]:=n;
  bar[3]:=1;
  bar[4]:=2;
  way:=2;
  st[1]:=1;
  st[2]:=1;
  st[3]:=n;
  st[4]:=n;
  for j:=1 to n do a[j+1,1]:=a[j,1]+1;
  repeat
   case way of
   1: begin
       for i:=st[1] to bar[1] do
        a[i+1,bar[4]+1]:=a[i,bar[4]+1]+1;
       way:=2;
       st[1]:=st[1]+1;
       bar[1]:=bar[1]-1;
      end;

   2: begin
       for i:=st[2] to bar[2] do
        a[bar[1]+1,i+1]:=a[bar[1]+1,i]+1;
       way:=3;
       st[2]:=st[2]+1;
       bar[2]:=bar[2]-1;
      end;

   3: begin
       for i:=st[3] downto bar[3] do
        a[i-1, bar[2]+1]:=a[i,bar[2]+1]+1;
       way:=4;
       st[3]:=st[3]-1;
       bar[3]:=bar[3]+1;
      end;

   4: begin
       for i:=st[4] downto bar[4] do
        a[bar[3]+1, i-1]:=a[bar[3]+1,i]+1;
       way:=1;
       st[4]:=st[4]-1;
       bar[4]:=bar[4]+1;
      end;
     end;
  until (bar[1]<st[1]) or (bar[2]<st[2]) or (bar[3]>st[3]) or (bar[4]>st[4]);

  for i:=1 to n do
   begin
    for j:=1 to n do
     write (a[i,j], ' ');
     writeln;
   end;
  close(input);
  close(output);
end.
