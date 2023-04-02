program xnet;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const MaxQ = 100100;

var a : array [0..100000, 0..100] of integer;
    t, n, i, j, st, en : integer;
    color : array [0..100000] of boolean;
    q : array [1..MaxQ] of integer;
    tail, head : integer;
    dist : array [0..100000] of integer;

procedure push (u : integer);
begin
 q[tail]:=u;
 inc(tail);
 if tail>MaxQ then
  tail:=1;
end;

function take : integer;
begin
 take:=q[head];
 inc (head);
 if head>MaxQ then
  head:=1;
end;

function IsEmpty : boolean;
begin
 IsEmpty:=(head=tail);
end;

procedure BFS (u : integer);
var i : integer;

begin
 head:=1;
 tail:=1;
 push (u);

 while not IsEmpty do
 begin
  u := take;
  for i:=1 to a[u,0] do
  begin
   if  (not color[a[u,i]]) then
   begin
    color[a[u,i]]:=true;
    push (a[u,i]);
    dist[a[u,i]]:=dist[u]+1;
   end;
  end;
 end;
end;



begin
  assign(input,'xnet.in');
  reset(input);
  assign(output,'xnet.out');
  rewrite(output);

  readln (n);
  for i:=0 to n-1 do
  begin
   read (t);
   read (a[t,0]);
   for j:=1 to a[t,0] do read (a[t,j]);
   readln;
  end;
  readln (st, en);

  dist[st]:=0;
  color[st]:=true;
  bfs(st);
  writeln (st, ' ', en, ' ', dist[en]-1);
  
  close(input);
  close(output);
end.
