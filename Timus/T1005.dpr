{$apptype console}

uses
	sysutils;

var n, i, sum, sum2, dif, curdif, tomove : integer;
    w : array[0..30] of integer;
    pile : array [0..30] of boolean;
    res : boolean;

procedure QS (var a : array of integer; l, r : integer);
var mid, t : integer;
    i, j : integer;

begin
 mid:=a[(l+r)div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]<mid do inc (i);
  while a[j]>mid do dec (j);
  if i<=j then
  begin
   t:=a[i];
   a[i]:=a[j];
   a[j]:=t;
   inc(i);
   dec(j);
  end;
 until i>j;
 if i<r then QS (a, i, r);
 if j>l then QS (a, l, j);
end;


begin
 assign (input,'T1005.in');
 reset (input);
 assign (output,'T1005.out');
 rewrite(output);

 readln (n);
 i:=0;
 while not seekeof do
 begin
  read (w[i]);
  inc(i);
 end;

 QS (w, 0, n-1);

 sum:=0;
 pile[n-1]:=true;
 for i:=0 to n-2 do
  sum:=sum+w[i];

 sum2:=w[n-1]; 
 dif:=abs(sum-sum2);
 while not res do
 begin
  res:=true;
  CurDif:=dif;
  ToMove:=n;
  for i:=0 to n-2 do
  begin
   if (not pile[i]) and (abs (sum-w[i]-sum2-w[i]) < curdif) then
   begin
    curdif:=abs(sum-w[i]-sum2-w[i]);
    ToMove:=i;
    res:=false;
   end;  
  end;
  dif:=CurDif;
  sum:=sum-w[ToMove];
  sum2:=sum2+w[ToMove];
  pile[ToMove]:=true;
 end;

 writeln (dif);
 
 close (input);
 close (output);
end.
