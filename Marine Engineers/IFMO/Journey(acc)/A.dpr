program D;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type location = record
      x, y  : integer;
      end;

var color : array [1..26, 1..26] of boolean;
    test, cur, p, q, k, s, i : integer;
    ans : array [1..800] of location;
    u : location;
    dx : array [1..8] of integer = (-2, -2, -1, -1, 1,  1,   2,  2  );
    dy : array [1..8] of integer = (-1,  1, -2,  2,  -2, 2,  -1,  1  );
    res : boolean;

procedure answer;
var i : integer;

begin
 writeln ('Scenario #', cur, ':');
 for i:=1 to k-1 do
  write (chr(65+ans[i].x-1), ans[i].y);
  writeln;
  writeln;
end;

procedure per (u : location);
var i : integer;
    v : location;

begin
 if k>s then
 begin
  answer;
  res:=true;
 end;
 if res then exit;
 color[u.y, u.x]:=true;
 for i:=1 to 8 do
 begin
  v.x:=u.x+dx[i];
  v.y:=u.y+dy[i];
  if (v.x>0) and (v.x<=q) and (v.y>0) and (v.y<=p) and (not color[v.y, v.x])
   then
   begin
    ans[k]:=v;
    inc(k);
    per (v);
    dec(k);
    color[v.y, v.x]:=false;
   end;
 end;
end;


begin
 assign (input,'journey.in');
 assign (output,'journey.out');
 reset(input);
 rewrite(output);

 readln (test);
 for cur:=1 to test do
 begin
  res:=false;
  for i:=1 to p do
  for k:=1 to q do color[i,k]:=false;
  for i:=1 to s do
  begin
   ans[i].x:=0;
   ans[i].y:=0;
  end;

  readln (p, q);
  s:=p*q;
  k:=2;
  u.y:=1;
  u.x:=1;
  ans[1]:=u;
  per (u);
  if not res then
  begin
   writeln ('Scenario #', cur, ':');
   writeln ('impossible');
   writeln;
  end;
 end;

 close(input);
 close(output);
end.
