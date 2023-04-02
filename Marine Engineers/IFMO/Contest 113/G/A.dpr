program train;

{$APPTYPE CONSOLE}


uses
  SysUtils;

var a : array [0..200000] of integer;
    track : array of array of integer;
    n, n2,m,i,j,put, way, step, k:integer;
    ins, fin, err : boolean;
    ans, ans2 : array [1..200000] of integer;
    
begin
 assign (input, 'input.txt');
 assign (output, 'output.txt');
 rewrite (output);
 reset (input);
 n:=1;
 while n<>0 do
 begin
  fin:=false;
  err:=false;
  readln(n,m);
  for i:=0 to n-1 do read(a[i]);
  put:=1;
  way:=1;
  setlength (track, 1, 2);
  track [0,0]:=1;
  track [0,1]:=a[0];
  n2:=2;
  step:=2;
  ans[1]:=1;
  if n<>0 then
  while not fin do
  begin
   ins:=false;
   for i:=0 to way-1 do
   begin
    if track[i, track[i,0]]<a[put] then
    begin
     inc(track[i,0]);
     if track[i,0]>n2-1 then n2:=track[i,0]+1;
     setlength (track,way,n2);
     track[i,track[i,0]]:=a[put];
     ans[step]:=i+1;
     inc (step);
     ins:=true;
     break;
    end;
   end;

   if not ins then
   begin
    if way<m then
    begin
     inc(way);
     setlength (track,way, n2);
     track[way-1, 0]:=1;
     track[way-1, 1]:=a[put];
     ans[step]:=way;
     inc (step);
    end

    else
    begin
     writeln('Transportation failed');
     fin:=true;
     err:=true;
    end;
   end;

   if put=n-1 then fin:=true;
   inc(put);
  end;

  if n<>0 then
  if not err then
  begin
   for i:=1 to step-1 do write (ans[i], ' ');
   writeln;
  end;

  step:=1;
  if not err then
  for i:=1 to n do
  begin
   for j:=0 to way-1 do
   begin
    if track [j, 1] = i then
    begin
     ans2[step]:=j+1;
     inc (step);
     track[j,1]:=0;
     k:=2;
     while k<=track[j,0] do
     begin
      if track[j,k]<>0 then
      begin
       track [j,1]:=track[j,k];
       track [j,k]:=0;
      end;
      inc(k);
     end;
    end;
   end;
  end;
  if n<>0 then
  if not err then
  begin
   for i:=1 to step-1 do write (ans2[i], ' ');
   writeln;
  end;
 end;
 close (input);
 close (output);
end.
