program D2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var queue :array[1..100,1..100] of string;
    numbers: array [1..100] of byte;
    S,T:string;
    n,i,d,test,cur,index,j,k: integer;




procedure proc(a,st:string);
var b: string;
    index: integer;
begin
  n:=0;
  repeat
  while a[i]<>st do inc(j);
  queue[n,1]:=st;
  numbers[n]:=i;
  if n<2 then index:=n;
  inc(n);
  until this>length(a);
    b:=copy(b,numbers[1],numbers[2]-numbers[1]);
  proc(b,a[n+1]);

end;




begin
 assign (input,'dna.in');
 assign (output,'dna.out');
 reset(input);
 rewrite(output);

readln (test);
for cur:=1 to test do
begin

readln(S); readln(T);

n:=1;

for i:=1 to length(t) do
 begin
  proc(t,t[i]);

 
 end;
  

end;


 close(input);
 close(output);
end.
