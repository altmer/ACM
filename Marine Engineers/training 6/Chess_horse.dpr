program Chess_horse;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const maxn=100;

var n, i, j : integer;
    a : array [1..maxn, 1..maxn] of integer;

procedure write_ans;
var i, j : integer;

begin
  for i:=1 to n do
  begin
  for j:=1 to n do
  write (a[i,j],' ');
  writeln;
  end;
end;

procedure bt (k, l, num : integer);
var i : integer;

begin

 if num=n*n then
 begin
  write_ans;
  halt;
 end;

 inc(num);
 if (k+2<n) and (l+1<n) and (a[k+2,l+1]=0) then
 begin
  a[k+2,l+1]:=num;
  bt (k+2, l+1, num);
  a[k+2,l+1]:=0;
 end;

 if (k+2<n) and (l-1>0) and (a[k+2,l-1]=0) then
 begin
  a[k+2,l-1]:=num;
  bt (k+2, l-1, num);
  a[k+2,l-1]:=0;
 end;

 if (k-2>0) and (l+1<n) and (a[k-2,l+1]=0) then
 begin
  a[k-2,l+1]:=num;
  bt (k-2, l+1, num);
  a[k-2,l+1]:=0;
 end;

 if (k-2>0) and (l-1>0) and (a[k-2,l-1]=0) then
 begin
  a[k-2,l-1]:=num;
  bt (k-2, l-1, num);
  a[k-2,l-1]:=0;
 end;

 if (k+1<n) and (l+2<n) and (a[k+1,l+2]=0) then
 begin
  a[k+1,l+2]:=num;
  bt (k+1, l+2, num);
  a[k+1,l+2]:=0;
 end;

 if (k+1<n) and (l-2>0) and (a[k+1,l-2]=0) then
 begin
  a[k+1,l-2]:=num;
  bt (k+1, l-2, num);
  a[k+1,l-2]:=0;
 end;

 if (k-1>0) and (l+2<n) and (a[k-1,l+2]=0) then
 begin
  a[k-1,l+2]:=num;
  bt (k-1, l+2, num);
  a[k-1,l+2]:=0;
 end;

 if (k-1>0) and (l-2>0) and (a[k-1,l-2]=0) then
 begin
  a[k-1,l-2]:=num;
  bt (k-1, l-2, num);
  a[k-1,l-2]:=0;
 end;
end;

begin
  assign (input,'chess.in');
  assign (output,'chess.out');
  reset(input);
  rewrite(output);
  readln (n);
  a[1,1]:=1;
  bt (1, 1, 1);
  close (input);
  close (output);
end.
