program B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const white = 0;
      grey = 1;
      North = 2;
      South = 1;
      West = 4;
      East = 3;

type location = record
      x, y : integer;
      end;

var q : array [1..1000] of location;
    tail, head : integer;
    st, en, u, v : location;
    d : array [0..6, 0..6, 1..4] of boolean;
    color : array [0..6, 0..6] of byte;
    dx : array [1..4] of integer = (0,  0, 1, -1);
    dy : array [1..4] of integer = (1, -1, 0,  0);
    ch : array [1..4] of char = ('S', 'N', 'E', 'W');
    WE, WS : location;
    par : array [0..6, 0..6] of integer;
    i, j, k : integer;
    ans : array [1..100] of char;

procedure push (u : location);

begin
 q[tail]:=u;
 inc(tail);
end;

function take : location;

begin
 take:=q[head];
 inc (head);
end;

function IsEmpty : boolean;

begin
 IsEmpty:=(head=tail);
end;

procedure BFS (u : location);
var v : location;
    i : integer;

begin
 head:=1;
 tail:=1;
 push (u);

 while not IsEmpty do
 begin
  u := take;
  for i:=1 to 4 do
  begin
   v.x:=u.x+dx[i];
   v.y:=u.y+dy[i];
   if  (not d[u.y, u.x, i]) and (color[v.y, v.x] = white) then
   begin
    color [v.y, v.x]:=grey;
    push (v);
    par[v.y, v.x]:=i;
   end;
  end;
 end;
end;


begin
 assign (input,'b.in');
 assign (output,'b.out');
 reset(input);
 rewrite(output);

 while not seekeof do
 begin
  readln (st.x, st.y);
  if (st.x + st.y<>0) then
  begin
    for i:=0 to 6 do
    for j:=0 to 6 do
    begin
     par[i, j]:=0;
     color [i,j]:=0;
     d[i, j, West] := false;
     d[i, j, North] := false;
     d[i, j, East] := false;
     d[i, j, South] := false;
    end;

    for i:=1 to 6 do
    begin
     d[i, 1, West] := true;
     d[1, i, North] := true;
     d[i, 6, East] := true;
     d[6, i, South] := true;
    end;

   readln (en.x, en.y);
   
   for i:=1 to 3 do
   begin
    readln (WS.x, WS.y, WE.x, WE.y);
    if WS.x - WE.x = 0 then
    begin
     for j:=WS.y+1 to WE.y do
     begin
      d[j, WS.x, East] := true;
      d[j, WS.x+1, West] := true;
     end;
    end

    else
    begin
     for j:=WS.x+1 to WE.x do
     begin
      d[WS.y, j, South] := true;
      d[WS.y+1, j, North] := true;
     end;
    end;
   end;
   bfs (st);
   u:=en;
   v:=en;
   k:=1;
   while (v.x<>st.x) or (v.y<>st.y) do
   begin
    u:=v;
    ans[k]:=ch[par[u.y, u.x]];
    v.x:=u.x-dx[par[u.y, u.x]];
    v.y:=u.y-dy[par[u.y, u.x]];
    inc (k);
   end;
   for i:=k-1 downto 1 do
    write (ans[i]);
   writeln;
  end;
 end;



 close(input);
 close(output);
end.
