program F;
{$APPTYPE CONSOLE}

uses
  SysUtils;

var s : string;
    a : array [1..2,1..2] of integer;
    i, j, n, k, l  : integer;
    res : boolean;
    c1, c2, c3, c4, ans : array [1..100000] of integer; {c1 - uu; c2 - ui; c3 - iu; c4 - ii}
    i1 : integer = 1;
    i2 : integer = 1;
    i3 : integer = 1;
    i4 : integer = 1;

procedure dfs (u : integer);
var v : integer;

begin
  v:=u;
  if a[u,v]<>0 then
   begin
    dec(a[u,v]);
    if u = v then
    begin
     if u = 1 then
     begin
      ans[i]:=c1[i1];
      inc(i);
      inc(i1);
     end

     else
     begin
      ans[i]:=c4[i4];
      inc(i);
      inc(i4);
     end;
    end

    else if u=1 then
    begin
     ans[i]:=c2[i2];
     inc(i);
     inc(i2);
    end

    else
    begin
     ans[i]:=c3[i3];
     inc(i);
     inc(i3);
    end;
    dfs (v);
   end;

   for v:=1 to 2 do
       if a[u,v]<>0 then
   begin
    dec(a[u,v]);
    if u = v then
    begin
     if u = 1 then
     begin
      ans[i]:=c1[i1];
      inc(i);
      inc(i1);
     end

     else
     begin
      ans[i]:=c4[i4];
      inc(i);
      inc(i4);
     end;
    end

    else if u=1 then
    begin
     ans[i]:=c2[i2];
     inc(i);
     inc(i2);
    end

    else
    begin
     ans[i]:=c3[i3];
     inc(i);
     inc(i3);
    end;
    dfs (v);
   end;
end;

begin
 assign (input,'network.in');
 assign (output,'network.out');
 reset(input);
 rewrite(output);

 readln (n);
 for k:=1 to n do
 begin
  readln (s);
  l:=1;
  while (s[l]<>'U') and (s[l]<>'I') do inc (l);
  if s[l]='U' then
  begin
   i:=1;
   l:=l+1;
   while (s[l]<>'U') and (s[l]<>'I') do inc (l);
   if s[l]='U' then
   begin
    j:=1;
    c1[i1]:=k;
    inc(i1);
   end
   else
   begin
    j:=2;
    c2[i2]:=k;
    inc(i2);
   end;
  end
  else
  begin
   i:=2;
   l:=l+1;
   while (s[l]<>'U') and (s[l]<>'I') do inc (l);

   if s[l]='U' then
   begin
    j:=1;
    c3[i3]:=k;
    inc(i3);
   end
   else
   begin
    c4[i4]:=k;
    inc(i4);
    j:=2;
   end;
  end;
  inc (a[i,j]);
 end;

 if abs(a[1,2] - a[2,1])>1 then res:=false

 else if a[1,2] - a[2,1] = 0 then
 begin
  if (a[1,1]=0) or (a[2,2]=0) then res:=true else res:=false;
 end

 else res:=true;

 if res then
 begin
  i:=1;
  i1:=1;
  i2:=1;
  i3:=1;
  i4:=1;
  if a[1,2] - a[2,1] = 0 then j:=1 else

  if a[1,2] - a[2,1] = 1 then j:=1 else j:=2;
  dfs (j);
  writeln ('YES');
  for j:=1 to i-1 do write (ans[j], ' ');
 end

 else writeln ('NO');

 close(input);
 close(output);
end.
