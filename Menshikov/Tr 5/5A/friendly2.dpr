program friendly2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var sum : array [1..1000000] of integer;
    bool : array [1..1000000] of boolean;
    i : integer;

function find_sum (n : integer) : integer;
var i, sum : integer;

begin
 sum:=1;
 for i:=2 to round(sqrt (n)) do
 begin
  if n mod i = 0 then
   sum:=sum+i+ (n div i);
 end;
 find_sum:=sum;
end;

begin
 assign(output,'friendly.out');
 rewrite(output);
 sum[1]:=0;
 bool[1]:=true;

 for i:=2 to 1000000 do
 begin
  if not bool[i] then
  begin
   sum[i]:=find_sum(i);
   bool[i]:=true;
  end;

  if not bool[sum[i]] then
  begin
   sum[sum[i]]:=find_sum(sum[i]);
   bool[sum[i]]:=true;
  end;

  if i=sum[sum[i]] then
   writeln (i, ' ', sum[i]);
  
 end;

 close(output);
end.
