program T1069;
{$apptype console}

uses
  sysutils;

type edge = record
      v1, v2 : integer;
     end;

var i, n, k, h, u, step : integer;
    code, len : array [1..7500] of integer;
    NotToUse : array [1..7500] of boolean;
    a : array [0..1400000] of edge;
    find : boolean;

function IsLess (a, b : edge) : boolean;

begin
 if a.v1>b.v1 then IsLess:=false

 else if a.v1=b.v1 then
 begin
  if a.v2>=b.v2 then IsLess:=false else IsLess:=true;
 end

 else IsLess:=true;
end;

function IsMore (a, b : edge) : boolean;

begin
 if a.v1<b.v1 then IsMore:=false

 else if a.v1=b.v1 then
 begin
  if a.v2<=b.v2 then IsMore:=false else IsMore:=true;
 end

 else IsMore:=true;
end;

procedure qs (var a : array of edge; l, r : integer);
var
i, j : integer;
mid, t : edge;

begin
i:=l;
j:=r;
mid:=a[(i+j)div 2];
repeat
 while IsLess(a[i], mid) do inc (i);
 while IsMore(a[j], mid) do dec (j);
 if i<=j then
 begin
  t:=a[i];
  a[i]:=a[j];
  a[j] :=t ;
  inc(i);
  dec(j);
 end;
until i>j;
if l<j then qs(a,l,j);
if r>i then qs(a,i,r);
end;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1069.in');
 reset(input);
 assign(output, 'T1069.out');
 rewrite(output);
{$ENDIF}

 i:=1;
 while not eoln do
 begin
  read (code[i]);
  inc(len[code[i]]);
  nottouse[code[i]]:=true;
  inc(i);
 end;
 n:=code[i-1];

 step:=0;
 for i:=1 to n-1 do
 begin
  k:=1;
  find:=false;
  while not find do
  begin
   if not nottouse[k] then
   begin
    NotToUse[k]:=true;
    find:=true;
    dec(k);
   end;
   inc(k);
  end;
  dec(len[code[i]]);
  h:=code[i];
  u:=k;
  if len[code[i]]=0 then NotToUse[code[i]]:=false;
  a[step].v1:=h;
  a[step].v2:=u;
  a[step+1].v1:=u;
  a[step+1].v2:=h;
  inc(step,2);
 end;

 qs (a,0, step-1);

 step:=0;
 for i:=0 to n-1 do
 begin
  k:=i+1;
  write (i+1, ': ');
  while a[step].v1=k do
  begin
   write(a[step].v2, ' ');
   inc(step);
  end;
  writeln;
 end;
 
{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
