program barrel;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type

 word = record
  w : string;
  n : integer;
 end;

var d, i , j, temp :integer ;
    words : array [0..50000] of string;
    numbers : array [0..50000] of word;
    matrix: array ['a'..'z'] of byte =(2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0);
    number, tmp: string;
    boo : array [0..50000] of boolean;
    execute : boolean;
    step : integer = 1;
    ans : array [1..50000] of string;
    stri : array [1..10000] of string;

function search (c : char; l, r : integer) : integer;

begin
 if r-l <> 1 then
 begin
  if boo[l+((r-l) div 2)] = false then
  begin
   if numbers [l+((r-l) div 2)].w[1] = c then
   begin
    temp:= l+((r-l) div 2);
    execute := true;
   end
   else if numbers [l+((r-l) div 2)].w[1] > c then search (c, l, l+((r-l) div 2))
   else search (c, l+((r-l) div 2), r);
  end

  else
  begin
    if numbers [l+((r-l) div 2)].w[1] <= c then search (c, l+((r-l) div 2), r)
     else search (c, l, l+((r-l) div 2));
   end;
 end

 else if numbers [r].w[1]=c then
  begin
    temp:= r;
    execute := true;
  end;
 search:=temp;
end;

procedure permut (pos : integer);
var m : integer;
    s : string;

begin
 repeat
  m:=0;
  execute:=false;
  m:=search (number[pos], 0, d-1);
  boo[m]:=true;
  if execute then
  begin
   if copy(number,pos,length(numbers[m].w)) = numbers[m].w then
   begin
    ans[step]:=words[numbers[m].n];
    inc(step);
    permut (pos+length(numbers[m].w));
    ans[step]:='';
    dec(step);
   end;
  end;
 until not execute;
end;

procedure   QuickSort(var a:array of word; L,R: integer);
var i,j:integer;
    Mid, T :word;
  begin
   i:=l; j:=R; Mid:=a[(i+j) div 2];
   repeat
    while A[i].w<Mid.w do i:=i+1;
    while a[j].w>Mid.w do j:=j-1;
     if i<=j then
      begin
       t:=a[i]; a[i]:=a[j]; a[j]:=t; i:=i+1; j:=j-1;
      end;
   until i>j;
   if L<j then QuickSort(A,L,j);
   if i<R then QuickSort(A,i,R);
   end;

Begin
  assign (input,'telefon.in');
  assign (output,'telefon.out');
  reset(input);
  rewrite(output);

repeat
readln(number);
if number<>'-1' then
 begin
  readln(d);
  for i:=0 to d-1 do
   begin
   readln(words[i]);
   numbers[i].n:=i;
   numbers[i].w:=words[i];
   for j:=1 to length(words[i]) do
    begin
    tmp:=inttostr(matrix[words[i,j]]);
    numbers[i].w[j]:=tmp[1];
    end;
  end;
  QuickSort(numbers,0,d-1);
  permut (1);

 end;
until number='-1';

  close(input);
  close(output);
end.
