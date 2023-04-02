program T1080;
{$apptype console}

uses
  sysutils;

const maxN=100;

var a : array [1..maxN, 1..maxN] of integer;
    n, i, k : integer;
    color : array [1..maxN] of boolean;
    q : array [1..10000] of integer;
    head, tail : integer;
    dist : array [1..maxn] of integer;
    res : boolean = false;

procedure push (u : integer);

begin
 q[tail]:=u;
 inc (tail);
end;

function take : integer;

begin
 take:=q[head];
 inc (head);
end;

function IsEmpty : boolean;

begin
 IsEmpty:=(head=tail);
end;

procedure BFS (u : integer);
var v : integer;

begin
 color[u]:=true;
 dist[u]:=0;
 head:=1;
 tail:=1;
 push(u);
 while not IsEmpty do
 begin
  u:=take;
  for v:=1 to n do
  begin
   if (a[u,v]<>0) and (not color[v]) then
   begin
    color[v]:=true;
    push(v);
    dist[v]:=dist[u]+1;
    a[u,v]:=0;
    a[v,u]:=0;
   end

   else if (a[u,v]<>0) and (color[v]) then
   if odd(dist[v])=odd(dist[u]) then
   begin
    res:=true;
    exit;
   end;
  end;
 end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1080.in');
 reset(input);
 assign(output, 'T1080.out');
 rewrite(output);
{$ENDIF}

 readln (n);

 for i:=1 to n do
 begin
  read (k);
  while k<>0 do
  begin
   a[i,k]:=1;
   a[k,i]:=1;
   read (k);   
  end;
 end;

 BFS(1);

 if res then write (-1)

 else
 begin
  for i:=1 to n do
   write(integer(odd(dist[i])));
 end;

{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
