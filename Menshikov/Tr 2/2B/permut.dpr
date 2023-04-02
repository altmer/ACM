program permutx;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type str = array [1..8] of char;

var
 a, ans : str;
 i, j, num : integer;

function suit (sym : char; ans : str) : boolean;
var i:integer;

begin
 for i:=1 to num do if sym<>ans[i] then suit:=true
 else
 begin
  suit:=false;
  break;
 end;
end;

procedure permut (n : integer; var ans : str);
var i : integer;

begin
 if n=num+1 then
 begin
  for i:=1 to num do write (ans[i]);
  writeln;
 end
 else
  begin
   for i:=1 to num do
   if suit(a[i],ans) then
   begin
    ans[n]:=a[i];
    permut (n+1, ans);
    ans[n]:='.';
   end;
  end;
end;

begin
 assign (input,'permut.in');
 reset (input);
 assign (output,'permut.out');
 rewrite(output);
 num:=1;
 while not seekeof do
 begin
  read (a[num]);
  inc(num);
 end;
 dec(num);
 for i:=1 to num do
 begin
  ans[1]:=a[i];
  permut (2, ans);
 end;
 close (input);
 close (output);
end.
