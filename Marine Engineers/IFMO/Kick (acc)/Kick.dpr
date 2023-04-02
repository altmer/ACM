program Kick;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
  score = record
   x, y : integer;
   end;

  player = record
   num, nam : integer;
   end;

var scen, p, r, g : byte;
    name : array [0..50] of string;
    str : string;
    res, guess : score;
    point : array [0..50] of player;
    dot : array [0..50] of player;
    round : array [0..50] of player;
    i,j,k,l,m : integer;
    max : integer;

function IsMore (a, b : player) : boolean;
begin
 if a.num>b.num then ismore:=true
  else if a.num=b.num then
   begin
    if dot[a.nam].num>dot[b.nam].num then ismore:=true
    else if dot[a.nam].num=dot[b.nam].num then
     begin
      if a.nam<b.nam then ismore:=true else ismore:=false;
     end
    else ismore:=false;
   end

  else ismore:=false;
end;


procedure QuickSort(var a : array of player; L,R: integer);
var i,j : integer;
    Mid,T : player;

begin
   i:=l; j:=R; Mid:=a[(i+j) div 2];
   repeat
    while A[i].num>Mid.num do i:=i+1;
    while a[j].num<Mid.num do j:=j-1;
     if i<=j then
      begin
       t:=a[i]; a[i]:=a[j]; a[j]:=t; i:=i+1; j:=j-1;
      end;
   until i>j;
   if L<j then QuickSort(A,L,j);
   if i<R then QuickSort(A,i,R);
end;

procedure QS(var a : array of player; L,R: integer);
var i,j : integer;
    Mid,T : player;
    fin : boolean;

begin
   i:=l; j:=R; Mid:=a[(i+j) div 2];
   repeat
    while ismore(a[i], mid) do inc (i);
    while not ismore (a[j],mid) do dec (j);
     if i<=j then
      begin
       t:=a[i]; a[i]:=a[j]; a[j]:=t; i:=i+1; j:=j-1;
      end;

   until i>j;
   if L<j then QS(A,L,j);
   if i<R then QS(A,i,R);
end;


Begin
  assign (input,'Kick.in');
  assign (output,'Kick.out');
  reset(input);
  rewrite(output);

  readln (scen);
  for k:=1 to scen do
  begin
   readln(p,r);
   for m:=0 to p-1 do
   begin
    dot[m].num:=0;
    point[m].num:=0;
    point[m].nam:=m;
    round[m].nam:=m;
    dot[m].nam:=m;
   end;
   for i:=0 to p-1 do readln (name[i]);
   for i:=1 to r do
    begin
     readln (g);
     for m:=0 to p-1 do
     begin
      round[m].num:=0;
      round[m].nam:=m;
     end;
     for j:=1 to g do
      begin
       readln (str);
       l:=1;
       while str[l]<>' 'do inc(l);
       res.x:=strtoint(copy(str,1,l-1));
       res.y:=strtoint(copy(str,l+2,length(str)-l));

       for m:=0 to p-1 do
       begin
        round[m].nam:=m;
        readln (str);
        l:=1;
        while str[l]<>' 'do inc(l);
        guess.x:=strtoint(copy(str,1,l-1));
        guess.y:=strtoint(copy(str,l+2,length(str)-l));

        if (guess.x=res.x) and (guess.y=res.y) then
        begin
         round[m].num:=round[m].num+3;
         point[m].num:=point[m].num+3;
        end
        else if (guess.x-guess.y)*(res.x-res.y)>0 then
        begin
         round[m].num:=round[m].num+1;
         point[m].num:=point[m].num+1;
        end
        else if (guess.x-guess.y=0) and (res.x-res.y=0) then
        begin
         round[m].num:=round[m].num+1;
         point[m].num:=point[m].num+1;
        end;
       end;

      end;
     QuickSort (round, 0, p-1);
     m:=0;
     if round[m].num<>0 then
      while round[m].num=round[0].num do
      begin
       inc(dot[round[m].nam].num);
       inc(m);
      end;

   end;
   QS (point, 0, p-1);
   writeln ('Scenario #', k, ':');
   for i:=0 to p-1 do
    writeln (point[i].num,' ', dot[point[i].nam].num, ' ', name[point[i].nam]);
   writeln; 
  end;


  close(input);
  close(output);
end.
