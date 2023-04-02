program strings;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, i : integer;
    a : array [0..100] of string;

function IsLess (a, b : string) : boolean;
var i, k : integer;
    res : boolean;
    s : string;

begin
 res:=false;
 if length(a)=length(b) then result:=(a<b)

 else
 begin
  if length(a)<length(b) then
   k:=length(a)
  else
   k:=length(b);

  for i:=1 to k do
  begin
   if a[i]<>b[i] then
   begin
    result:=(a<b);
    res:=true;
    break;
   end;
  end;

  if res then exit;

  if length(a)<length(b) then
  begin
   s:= copy (b, k+1, length (b)-k);
   if length(a) <> length (s) then result:=IsLess (a, s)
   else
   if s<a then result:=false
    else result:=true;
  end
  else
  begin
   s:= copy (a, k+1, length (a)-k);
   if length(b)<>length(s) then result:=IsLess (s, b) else
   if s<b then result:=true
    else result:=false;
  end;
 end;
end;

function IsMore (a, b : string) : boolean;
var i, k : integer;
    res : boolean;
    s : string;

begin
 res:=false;
 if length(a)=length(b) then result:=(a>b)

 else
 begin
  if length(a)<length(b) then
   k:=length(a)
  else
   k:=length(b);

  for i:=1 to k do
  begin
   if a[i]<>b[i] then
   begin
    result:=(a>b);
    res:=true;
    break;
   end;
  end;

  if res then exit;

  if length(a)<length(b) then
  begin
   s:= copy (b, k+1, length (b)-k);
   if length(a)<>length(s) then result:=IsMore (a, s)
   else
   if s<a then result:=true
    else result:=false;
  end
  else
  begin
   s:= copy (a, k+1, length (a)-k);
   if length(b)<>length(s) then result:=IsMore (s, b)
   else
   if s<b then result:=false
    else result:=true;
  end;
 end;
end;

procedure QS (var a : array of string; l, r : integer);
var t, mid : string;
    i, j : integer;

begin
 i:=l; j:=r;
 mid:=a[(l+r) div 2];
 repeat
  while IsLess (a[i],mid) do inc (i);
  while IsMore (a[j],mid) do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc (i);
   dec (j);
  end;
 until i>j;
 if j>l then QS (a, l, j);
 if i<r then QS (a, i, r); 
end; 

begin
  assign (input, 'strings.in');
  assign (output, 'strings.out');
  reset (input);
  rewrite (output);

  readln (n);
  for i:=0 to n-1 do
   readln (a[i]);

  QS (a, 0, n-1);

  for i:=0 to n-1 do
   write(a[i]);

  

  close (input);
  close (output);
end.
