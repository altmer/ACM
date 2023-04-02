program piggy;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
 coin = record
  p, w : integer;
  end;

var c : array [1..500] of coin;
    m : array [0..9999] of integer;
    i, n, e, f : integer;
    weight, kind : integer;

begin
 assign (input,'piggy.in');
 reset (input);
 assign (output,'piggy.out');
 rewrite(output);

 readln (E, F);
 readln (n);
 for i:=1 to n do readln (c[i].p, c[i].w);

 m[0]:=0;
 for weight:=1 to 9999 do
 begin
  for kind:=1 to n do
  begin
   if (c[kind].w <= weight) and (m[weight-c[kind].w]<>-1) then
   begin
    if (m[weight]>0) and ((m[weight-c[kind].w]+c[kind].p)<m[weight])then
     m[weight]:=m[weight-c[kind].w]+c[kind].p
    else if (m[weight]<=0) then m[weight]:=m[weight-c[kind].w]+c[kind].p;
   end

   else if m[weight]=0 then m[weight]:=-1;
  end;
 end;

 if m[f-e] = -1 then
 begin
  writeln ('This is impossible.');
  halt;
 end

 else write (m[f-e], ' ');

 for i:=0 to 9999 do m[i]:=0;

 for weight:=1 to 9999 do
 begin
  for kind:=1 to n do
  begin
   if (c[kind].w <= weight) and (m[weight-c[kind].w]<>-1) then
   begin
    if (m[weight]>0) and ((m[weight-c[kind].w]+c[kind].p)>m[weight])then
     m[weight]:=m[weight-c[kind].w]+c[kind].p
    else if (m[weight]<=0) then m[weight]:=m[weight-c[kind].w]+c[kind].p;
   end

   else if m[weight]=0 then m[weight]:=-1;
  end;
 end;

 write (m[f-e]);
 
 close (input);
 close (output);
end.
