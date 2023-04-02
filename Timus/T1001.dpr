program T1001;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [1..150000] of extended;
    i : integer;

begin
 assign (input,'T1001.in');
 reset (input);
 assign (output,'T1001.out');
 rewrite(output);
 i:=0;
 while not seekeof do
 begin
  inc(i);
  read (a[i]);
 end;
 for i:=i downto 1 do writeln (sqrt(a[i]):0:4);

 close (input);
 close (output);
end.



