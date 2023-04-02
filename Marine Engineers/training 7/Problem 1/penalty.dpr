program penalty;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
 task = record
  time, res, att : integer;
  end;

var a : array [0..29] of task;
    n,i,ans,pen, add:integer;

procedure qs (var a : array of task; l, r : integer);
var
 i, j : integer;
 mid, t : task;

begin
 i:=l;
 j:=r;
 mid:=a[(i+j)div 2];
 repeat
  while a[i].time < mid.time do inc (i);
  while a[j].time > mid.time do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc(i);
   dec(j);
  end;
 until i>j;
 if l<j then qs (a,l,j);
 if r>i then qs (a,i,r);
end;

begin
  assign (input,'penalty.in');
  assign (output,'penalty.out');
  reset(input);
  rewrite(output);

  readln (n);
  for i:=0 to n-1 do read (a[i].time);
  readln;
  for i:=0 to n-1 do read (a[i].res);
  readln;
  for i:=0 to n-1 do read (a[i].att);

  qs (a,0, n-1);

  for i:=0 to n-1 do
  begin
   if a[i].res<>0 then
   begin
    add:=add+a[i].time;
    ans:=ans+add;
   end;
   pen:=pen+20*a[i].res*a[i].att;
  end;

  writeln (ans+pen);

  close(input);
  close(output);
end.
