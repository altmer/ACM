program Contest116;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const min=10;
      up=11;
      down=12;  

var a : array [0..99, 0..99] of byte;
    b : array [0..12] of byte;
    i, j, st, en : integer;
    color : array [0..99] of boolean;
    dist : array [0..99] of integer;
    q : array [1..30032] of integer;
    head, tail : integer;

procedure push (u:integer);

begin
 q[tail]:=u;
 inc (tail);
end;

function take : integer;

begin
 result:=q[head];
 inc (head);
end;

function IsEmpty : boolean;

begin
 result:=(head=tail);
end;

procedure BFS (u : integer);
var v : integer;

begin
 color[u]:=true;
 head:=1;
 tail:=1;
 push(u);
 while not IsEmpty do
 begin
  u:=take;
  for v:=0 to 99 do
  begin
   if (color[v]) and (a[u,v]>0) then
   begin
    if dist[u]+a[u,v]<dist[v] then
    begin
     dist[v]:=dist[u]+a[u,v];
     push (v);
    end;
   end

   else if (not color[v]) and (a[u,v]>0) then
    begin
     dist[v]:=dist[u]+a[u,v];
     color[v]:=true;
     push(v);
    end;
  end;
 end;
  
end;

begin
  assign (input, 'remote.in');
  assign (output, 'remote.out');
  reset (input);
  rewrite (output);

  readln (b[1], b[2], b[3], b[11]);
  readln (b[4], b[5], b[6], b[12]);
  readln (b[7], b[8], b[9]);
  readln (b[10], b[0]);

  for i:=0 to 99 do
   dist[i]:=0; 

  for i:=0 to 99 do
   for j:=0 to 99 do
   begin
    if i=j then a[i,j]:=0
    else if j<10 then
    begin
     if (b[j]=1) then a[i,j]:=1;
    end

    else
    begin
     if (b[min]=1) and (b[j div 10]=1) and (b[j mod 10]=1) then
      a[i,j]:=3;
    end;

    if b[up]=1 then
     if i+1>99 then
      a[i,0]:=1
       else a[i,i+1]:=1;

    if b[down]=1 then
     if i-1<0 then
      a[i,99]:=1
       else a[i,i-1]:=1;
  end;

 readln (st, en);
 dist[st]:=0;

 BFS (st);

 if dist[en]>0 then writeln (dist[en])
  else if st=en then writeln (0)
   else if dist[en]=0 then writeln (-1);

 close (input);
 close (output);
end.
