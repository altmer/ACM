program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   a:array [0..100000] of integer;
    i,n,time : int64;

begin
assign(input,'g.in');
assign(output,'g.out');
reset(input);
rewrite(output);
       i:=0;
while not eof do
begin
 readln(n);
 if n=0 then halt;
 i:=0;
 while i<n do
  begin
   read(a[i]);
   inc(i);
  end;
 readln;
 i:=0;
   while i<n do
    begin
    inc(i);
    a[i]:=a[i-1]+a[i];
    time:=abs(a[i-1])+time;
    end;
 writeln(time);
 time:=0;
 n:=0;
end;


                   close(input);
                   close(output);
end.
