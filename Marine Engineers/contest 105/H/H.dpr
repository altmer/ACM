program H;

{$APPTYPE CONSOLE}

uses
  SysUtils;
// '-' - 45

const draw = 2;
      win = 1;
      lose = -1;

type inf = record
      name : string;
      team : integer;
      num : integer;
      end;

var i, j, n, numpl : integer;
    games : array [1..500, 1..500] of integer;
    pl : array [1..500] of inf;
    num1, num2 : integer;
    answer : array [1..250, 1..250] of integer;
    points : array [1..2, 1..250] of integer; 


procedure scanf;

var s, nam : string;
    i, j : integer;
    n : array [1..2] of integer;
    fin : boolean;
    k, l : integer;
    sc1, sc2 : integer;

begin
 readln (s);
 i:=1;
 while (ord(s[i])<33) or (ord(s[i])>126) or (s[i]='-') do inc(i);
 while (ord(s[i])>=33) and (ord(s[i])<=126) and (s[i]<>'-') do
 begin
  nam:=nam+s[i];
  inc(i);
 end;

 for j:=1 to numpl do
  if pl[j].name = nam then
  begin
   k:=j;
   fin:=true;
   break;
  end;
 if not fin then
 begin
  inc (numpl);
  pl[numpl].name:=nam;
  k:=numpl;
 end;

 fin:=false;
 nam:='';

 while (ord(s[i])<33) or (ord(s[i])>126) or (s[i]='-') do inc(i);
 while (ord(s[i])>=33) and (ord(s[i])<=126) and (s[i]<>'-') do
 begin
  nam:=nam+s[i];
  inc(i);
 end;
 
 for j:=1 to numpl do
  if pl[j].name = nam then
  begin
   l:=j;
   fin:=true;
   break;
  end;
 if not fin then
 begin
  inc (numpl);
  pl[numpl].name:=nam;
  l:=numpl;
 end;

 nam:='';

 while (s[i]<'0') or (s[i]>'9') do inc (i);
 while (s[i]>='0') and (s[i]<='9') do
 begin
  nam:=nam+s[i];
  inc(i);
 end;
 sc1:=strtoint (nam);

 nam:='';

 while (s[i]<'0') or (s[i]>'9') do inc (i);
 while (s[i]>='0') and (s[i]<='9') do
 begin
  nam:=nam+s[i];
  inc (i);
 end;

 sc2:=strtoint (nam);
 if sc1>sc2 then
 begin
  games [k,l]:=win;
  games [l,k]:=lose;
 end

 else if sc1=sc2 then
 begin
  games [k,l]:=draw;
  games [l,k]:=draw;
 end

 else
 begin
  games [k,l]:=lose;
  games [l,k]:=win;
 end;
end;

begin
 assign (input,'h.in');
 assign (output,'h.out');
 reset(input);
 rewrite(output);

 readln (n);
 numpl:=0;
 for i:=1 to n do scanf;
 
 // деление на команды
 num1:=1;
 num2:=0;
 pl[1].team:=1;
 pl[1].num:=num1;
 for i:=2 to numpl do
  if games [1,i] <> 0 then
  begin
   pl[i].team:=2;
   inc(num2);
   pl[i].num:=num2;
  end

  else
  begin
   pl[i].team:=1;
   inc(num1);
   pl[i].num:=num1;
  end;

 writeln (num1, ' ', num2);
 
 for i:=1 to numpl do
 begin
  if pl[i].team=1 then
  begin
   for j:=1 to numpl do
   begin
    case games [i,j] of

    1:
    begin
     answer [pl[i].num, pl[j].num]:=games [i,j];
     points [1, pl[i].num]:=points [1, pl[i].num]+3;
    end;

    -1:
    begin
     answer [pl[i].num, pl[j].num]:=games [i,j];
     points [2, pl[j].num]:=points [2, pl[j].num]+3;
    end;

    2:
    begin
     answer [pl[i].num, pl[j].num]:=0;
     points [2, pl[j].num]:=points [2, pl[j].num]+1;
     points [1, pl[i].num]:=points [1, pl[i].num]+1;
    end;

    end;

   end;  
  end;
 end;

 for i:=1 to num1 do
 begin
  for j:=1 to num2 do
   write (answer[i, j], ' ');
  writeln (points[1, i]);
 end;
 for j:=1 to num2 do write (points[2, j], ' ');

 close(input);
 close(output);
end.
