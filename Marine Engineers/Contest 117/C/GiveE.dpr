program GiveE;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var n, num, n_tr, last, i, step : integer;
    a : array [0..19] of integer = (0, 2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56, 60, 62, 64, 66);
    tr : array [1..8] of integer;
    s : array [1..500000] of string;
    
begin

 n:=1;
 step:=1;
 while n<>0 do
 begin

  readln (n);
  if n<>0 then
  begin
  if n<20 then
  begin
   s[step]:=s[step]+inttostr(a[n]);
   inc(step);
  end

  else
  begin
  num:=n;
  n_tr:=0;
  while (num<>0) do
  begin
   inc(n_tr);
   num:=num div 20;
  end;

  num:=n;
  for i:=1 to n_tr do
  begin
   tr[i]:=num mod 20;
   num:=num div 20;
  end;

  s[step]:=s[step]+inttostr(a[tr[n_tr]]);
  if n_tr<>1 then
  begin
   s[step]:=s[step]+',';
  end;
  if n_tr=8 then
  begin
   s[step]:=s[step]+'000,000,';
  end;
  for i:=n_tr-1 downto 1 do
  begin
   s[step]:=s[step]+'0';
   if a[tr[i]] div 10 <> 0 then
   begin
    s[step]:=s[step]+inttostr(a[tr[i]]);
   end
    else
    begin
     s[step]:=s[step]+'0';
     s[step]:=s[step]+inttostr(a[tr[i]]);
    end;
   if i<>1 then
   begin
    s[step]:=s[step]+',';
   end;
  end;
  inc(step);
  end;
  end;
 end;

 for i:=1 to step-1 do
  writeln (s[i]);

  readln;
end.
