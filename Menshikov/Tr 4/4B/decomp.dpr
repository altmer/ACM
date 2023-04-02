program decomp;
{$APPTYPE CONSOLE}
uses SysUtils;

var n : integer;
    a : array [1..40] of byte;

procedure answer (k : integer);
var i : integer;

begin
 for i:=1 to k-1 do write(a[i], '+');
 writeln(a[k]);
end;

procedure track (k : integer; sum : integer; j : integer);
var i : integer;

begin
 if sum = n then
 begin
  answer (k-1);
  exit;
 end
 else if sum>n then exit;
 for i:=j to n-1 do
 begin
  a[k]:=i;
  sum:=sum+i;
  track (k+1, sum, i);
  sum:=sum-i;
 end;
end;

begin
 assign(input,'decomp.in');
 reset (input);
 assign(output,'decomp.out');
 rewrite(output);

 readln (n);
 track(1, 0, 1);
 
 close(input);
 close(output);
end.
