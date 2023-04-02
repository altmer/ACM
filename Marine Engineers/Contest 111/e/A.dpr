program D2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type location = record
      x, y : integer;
      end;

var test, curtest : integer;
    dx : array [1..8] of integer = (2,  2, -2, -2, 1,  1, -1, -1);
    dy : array [1..8] of integer = (1, -1,  1, -1, 2, -2,  2, -2);
    ans : array [1..676] of location;
    color : array [1..26, 1..26] of boolean;    
    p, q, k, step, j,i, s : integer;
    u : location;


procedure answer;
var i : integer;
begin
 for i:=1 to k-1 do write (p,q);
end;

procedure per (u : location);
var i : integer;
    v : location;

begin
 if step=s then
 begin
  answer;
  exit;
 end;
 for i:=1 to 8 do
 begin
  v.x:=u.x+dx[i];
  v.y:=u.y+dy[i];
  if (v.x>0) and (v.x<=q) and (v.y>0) and (v.y<=p) and (not color[v.y, v.x])
   then
   begin
    inc(step);
    ans [k]:=v;
    inc(k);
    color[v.y, v.x]:=true;
    per(v);
    dec(k);
    ans[k].x:=0;
    ans[k].y:=0;
    color[v.y, v.x]:=false;
    dec(step);
   end;
 end;
end;

begin
 assign (input,'journey.in');
 assign (output,'journey.out');
 reset(input);
 rewrite(output);

 readln (test);
 for curtest:=1 to test do
 begin
  readln (p, q);
  k:=2;
  step:=2;
  s:=p*q;
  u.x:=1;
  u.y:=1;
  ans[1]:=u;
  per (u);
 end;
 close(input);
 close(output);
end.
