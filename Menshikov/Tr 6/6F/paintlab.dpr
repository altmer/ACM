program paintlab;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var i, j, p : integer;
    n : integer;
    a : array [1..33, 1..33] of char;
    color : array [1..33, 1..33] of char;
    dx : array [1..4] of integer = (0,0,1,-1);
    dy: array [1..4] of integer = (1,-1,0,0);
    wall : integer;    

procedure dfs (k, l : integer);
var i : integer;

begin
 color [k,l] := 'g';
 for i:=1 to 4 do
  if (k+dy[i]<=n) and (k+dy[i]>0)and(l+dx[i]<=n)and(l+dx[i]>0)
   and (a[k+dy[i],l+dx[i]]='.') and (color[k+dy[i],l+dx[i]]='w')
    then dfs(k+dy[i], l+dx[i]);
end;


begin
 assign (input,'paintlab.in');
 reset (input);
 assign (output,'paintlab.out');
 rewrite(output);

 readln (n);
 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   read (a[i,j]);
   color [i,j]:='w';
  end;
  readln;
 end;

 dfs (1,1);
 if color [n,n] = 'w' then dfs (n,n);

 for i:=1 to n do
 begin
  for j:=1 to n do
  begin
   for p:=1 to 4 do
   begin
    if color [i,j]='g' then
    begin
     if (i+dy[p]>n) or (i+dy[p]=0) or (j+dx[p]>n)or (j+dx[p]<=0) then inc(wall)
      else if (color[i+dy[p],j+dx[p]]='w') then inc (wall);
    end;
   end;
  end;
 end;
 write (9*(wall-4));
 close (input);
 close (output);
end.



