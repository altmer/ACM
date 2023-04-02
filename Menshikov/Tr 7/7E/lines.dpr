program lines;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const
 MaxQ = 62500;
 Max = 250;

type
 location = record
  x, y : integer;
  end;

 queue = record
  mas : array [1..maxq] of location;
  head, tail : integer;
  end;

var i, j : integer;
    {k, l : integer;}
    n : integer;
    u, fin, path : location;
    Q : queue;
    a : array [1..max, 1..max] of char;
    color : array [1..max, 1..max] of char;
    d : array [1..max, 1..max] of integer;
    p : array [1..max, 1..max] of char;
    dx : array [1..4] of integer = (0,0,1,-1);
    dy : array [1..4] of integer = (1,-1,0,0);
    par : array [1..4] of char = ('u','d','l','r');

procedure push (v : location);

begin
 q.mas[q.tail] := v;
 inc(q.tail);
end;

function pop : location;

begin
 pop := q.mas[q.head];
 inc (q.head);
end;

function IsEmpty : boolean;

begin
 IsEmpty := (q.head=q.tail);
end;

procedure bfs (u : location);
var i : integer;
    v : location;

begin
 color [u.y,u.x] := 'g';
 d [u.y,u.x] := 0;
 q.head:=1;
 q.tail:=1;
 push (u);

 while not IsEmpty do
 begin
  u := pop;
  for i:=1 to 4 do
  begin
   v.x:=u.x+dx[i];
   v.y:=u.y+dy[i];

   if (v.y<=n) and (v.y>0)and(v.x<=n)and(v.x>0)
    and ((a[v.y,v.x]='.') or (a[v.y,v.x]='X')) and
     (color[v.y,v.x]='w')
     then
     begin
      color[v.y,v.x] := 'g';
      d [v.y,v.x] := d [u.y,u.x] + 1;
      p [v.y,v.x] := par[i];
      push(v);
     end;
   end;
 end;
end;

begin
 assign (input,'lines.in');
 reset (input);
 assign (output,'lines.out');
 rewrite(output);

 readln (n);
 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   read (a[i,j]);
   if a[i,j]='@' then
   begin
    u.x:=j;
    u.y:=i;
   end
   else if a[i,j]='X' then
   begin
    fin.x:=j;
    fin.y:=i;
   end;
   color [i,j]:='w';
   d[i,j]:=-1;
   p[i,j]:='N';
  end;
  readln;
 end;

 bfs (u);

 path:=fin;
 while d[path.y,path.x]<>0 do
 begin
  a[path.y,path.x]:='+';
  case p[path.y,path.x] of
   'u': dec(path.y);
   'r': inc(path.x);
   'l': dec(path.x);
   'd': inc(path.y);
   'N':
    begin
     writeln ('N');
     halt;
    end
   end;
 end;

 writeln ('Y');
 for i:=1 to n do
 begin
  for j:=1 to n do write (a[i,j]);
  writeln;
 end;
 close (input);
 close (output);
end.