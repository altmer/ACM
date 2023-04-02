program G;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var a : array [1..4] of integer;
    b : array [1..4] of integer;
    i, j, k, m, n, l, u, st, en, q, step, w : integer;
    r : real;
    s, ch, s1 : string;
    res : boolean;
    ans : array [1..10000] of string;
    t : char;

begin


 readln (n);
 s1:='abc';
 step:=1;
 for j:=1 to n do
 begin
  readln (m);
  for l:=1 to 4 do
   read (a[l]);
  readln (s);
  i:=1;
  for l:=1 to m do
  begin

   while (s[i]<'0') or (s[i]>'9') do inc (i);
   st:=i;
   while (s[i]>='0') and (s[i]<='9') do inc(i);
   en:=i-1;

   u:=4;
   while en>st do
   begin
    ch:=copy(s, en-1, 2);
    b[u]:=strtoint(ch);
    en:=en-2;
    dec(u);
   end;

   if en=st then
   begin
    ch:=s[st];
    b[u]:=strtoint(ch);
   end;

   k:=10000;
   while k<=999999 do
   begin
    r:=k/a[1];
    k:=trunc(r)+1;
    k:=k*a[1] + b[1];
    res:=true;
    for u:=1 to 4 do
     if (k mod a[u] <> b[u]) then
     begin
      res:=false;
      break;
     end;
    if res then
    begin
     q:=3;
     while k<>0 do
     begin
      w:=k mod 100;
      k:=k div 100;
      if (w<27) then s1[q]:=chr(W+64)
       else s1[q]:=' ';
      dec(q);
     end;
     ans[step]:=ans[step]+s1;
     break;
    end;
   end;
  end;
  inc(step);
 end;

 for i:=1 to step do
 begin
  writeln (ans[i]);
  
 end;

end.
