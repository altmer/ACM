program aplusb;
{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, n1, n2, k, i, j, peren : integer;
    v : array [1..100000] of string;
    a, b, cur : string;
    res : boolean;
    alph : string = 'abcdefghijklmnopqrstuvwxyz';
    c : string;

function BS (a : string; l, r : integer; TF : char) : integer;
var cur : integer;
begin
 result:=0;
 res:=false;
 while r-l>1 do
 begin
  if res then break;
  cur:=(l+r)div 2;
  if a[cur]=tf then
  begin
   result:=cur;
   break;
  end
  else if a[cur]>tf then result:=BS(a,l,cur,tf)
  else result:=BS(a,cur,r,tf);
 end;
 res:=true;
 if a[r]=tf then result:=r;
 if a[l]=tf then result:=l;
end;

begin
 assign (input,'aplusb.in');
 reset (input);
 assign (output,'aplusb.out');
 rewrite(output);

 readln (n, k);
 for i:=1 to k do
  readln (v[i]);
 readln (a);
 readln (b);
 peren:=0;
 setlength(c,n);
 for i:=n downto 1 do
 begin
  cur:=alph;
  for j:=1 to k do
   delete (cur,BS(cur,1,length(cur),v[j,i]),1);
  n1:=BS(cur, 1, length(cur),a[i])-1;
  n2:=BS(cur, 1, length(cur),b[i])-1;
  n:=n1+n2+peren;
  peren:=n div length(cur);
  c[i]:=cur[(n mod length(cur))+1];
 end;
 writeln (c);

 close (input);
 close (output);
end.
