program H;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type piece = record
      col : char;
      kind, row : integer;
      end;

var s : string;
    white, black : array [0..15] of piece;
    rank : array [1..6] of char = ('K', 'Q', 'R', 'B', 'N', 'P');
    let : array [1..8] of char = ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
    nb, nw : integer;
    i, j : integer;


procedure take (j, k : integer);
var i : integer;

begin
  if (s[j]>='a') and (s[j]<='z') then
  begin
   for i:=1 to 6 do
    if rank[i] = upcase(s[j]) then black[nb].kind:=i;
   black[nb].row:=k;
   black[nb].col:=let[round((j+1)/4)];
   inc (nb);
  end

  else if (s[j]>='A') and (s[j]<='Z') then
  begin
   for i:=1 to 6 do
    if rank[i] = s[j] then white[nw].kind:=i;
   white[nw].row:=k;
   white[nw].col:=let[round((j+1)/4)];
   inc (nw);
  end;
end;

function ismore_w (a, b : piece) : boolean;

begin
 if a.kind < b.kind then ismore_w := true

 else if a.kind=b.kind then
 begin

  if a.row<b.row then ismore_w := true
   else if a.row=b.row then
   begin
    if a.col<b.col then ismore_w := true
     else ismore_w := false;
   end
   else ismore_w := false;

 end

 else ismore_w:=false;
end;

function isless_w (a, b : piece) : boolean;

begin
 if a.kind > b.kind then isless_w := true

 else if a.kind=b.kind then
 begin
  if a.row>b.row then isless_w := true
   else if a.row=b.row then
   begin
    if a.col>b.col then isless_w := true
     else isless_w := false;
   end

   else isless_w := false;
 end

 else isless_w:=false;
end;


procedure sort_white (var a : array of piece;  l, r : integer);
var mid, t : piece;
    k, m : integer;

begin
 k:=l;
 m:=r;
 mid:=a[(k+m) div 2];
 repeat
 while ismore_w (a[k], mid) do inc (k);
 while isless_w (a[m], mid) do dec (m);
 if k<=m then
 begin
  t:=a[k];
  a[k]:=a[m];
  a[m]:=t;
  k:=k+1;
  m:=m-1;
 end;
 until k>m;

 if l<m then sort_white (a, l, m);
 if k<R then Sort_white (a,k,R);
end;

function ismore_b (a, b : piece) : boolean;

begin
 if a.kind < b.kind then ismore_b := true

 else if a.kind=b.kind then
 begin
  if a.row>b.row then ismore_b := true
   else if a.row=b.row then
   begin
    if a.col<b.col then ismore_b := true
     else ismore_b := false;
   end

   else ismore_b := false;
 end

 else ismore_b:=false;
end;

function isless_b (a, b : piece) : boolean;

begin
 if a.kind > b.kind then isless_b := true

 else if a.kind=b.kind then
 begin
  if a.row<b.row then isless_b := true
   else if a.row=b.row then
   begin
    if a.col>b.col then isless_b := true
     else isless_b := false;
   end

   else isless_b := false;
 end

 else isless_b:=false;
end;


procedure sort_black (var a : array of piece;  l, r : integer);
var mid, t : piece;
    i, j : integer;

begin
 i:=l;
 j:=r;
 mid:=a[(i+j)div 2];
 repeat
 while ismore_b (a[i], mid) do inc (i);
 while isless_b (a[j], mid) do dec (j);
 if i<=j then
 begin
  t:=a[i];
  a[i]:=a[j];
  a[j]:=t;
  i:=i+1;
  j:=j-1;
 end;
 until i>j;
 if l<j then sort_black (a, l, j);
 if i<R then Sort_black (a,i,R);
end;


begin
 assign (input,'h.in');
 assign (output,'h.out');
 reset(input);
 rewrite(output);
 nb:=0;
 nw:=0;

 for i:=8 downto 1 do
 begin
  readln (s);
  readln (s);
  for j:=1 to 8 do take (4*j-1, i);
 end;

 sort_white (white, 0, nw-1);
 sort_black (black, 0, nb-1);

 write ('White: ');
 for i:=0 to nw-1 do
 begin
  if white[i].kind<>6 then write (rank[white[i].kind], white[i].col, white[i].row)
   else write (white[i].col, white[i].row);
  if i<>nw-1 then write(',');
 end;
 writeln;
 write ('Black: ');
 for i:=0 to nb-1 do
 begin
  if Black[i].kind<>6 then write (rank[Black[i].kind], Black[i].col, Black[i].row)
   else write (Black[i].col, Black[i].row);
  if i<>nb-1 then write(',')
 end;

 close(input);
 close(output);
end.
