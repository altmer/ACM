program Chess_BT;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const maxn=1000;

var n, i, j : integer;
    a : array [1..maxn] of integer;

procedure write_ans;
var i, j : integer;

begin
  for i:=1 to n do
  begin
  for j:=1 to n do
  if a [j] = i then write ('X ') else write ('- ');
  writeln;
  end;
end;

function suit (k, i : integer) : boolean;
var l, m : integer;

begin
 suit:=true;
 for l:=1 to k-1 do
 begin
  if i<>a[l] then suit:=true
  else
   begin
    suit:=false;
    exit;
   end;

  if i<>a[l]+k-l then suit:=true
  else
   begin
    suit:=false;
    exit;
   end;

  if i<>a[l]-k+l then suit:=true
  else
   begin
    suit:=false;
    exit;
   end;
  end;
end;

procedure bt (k : integer);
var i : integer;

begin
 if k=n+1 then
 begin
  for i:=1 to n do write (a[i], ' ');
  writeln;
  write_ans;
  halt;
 end;

 for i:=1 to n do
 begin
  if suit(k,i) then
  begin
   a[k]:=i;
   bt(k+1);
  end;
 end;
end;

begin
  assign (input,'chess.in');
  assign (output,'chess.out');
  reset(input);
  rewrite(output);
  a[1]:=1;
  readln (n);
  bt (1);

  close (input);
  close (output);
end.
