program T1195;
{$apptype console}

uses
  sysutils;

const r = 100;
      c = 101;
      d=102;
      cross = 'Crosses win';
      outh = 'Ouths win';
      dr = 'Draw';

type ttype = record
      o, x, e : integer;
     end;

     coord = record
      i, j : integer;
     end;

label 1;
label 2;
label 3;

var a : array [0..3, 0..3] of char;
    m : array [1..3, r..d] of ttype;
    emp : array [1..3] of coord;
    win_x : array [1..3] of boolean;
    towin_x : array [1..3] of integer;
    win_o : array [1..3] of boolean;
    towin_o : array [1..3] of integer;
    i, j, step, k, l, max, toset : integer;

procedure set0;

begin
 for i:=1 to 3 do
 begin
  emp[i].i:=0;
  emp[i].j:=0;
  win_x[i]:=false;
  win_o[i]:=false;
  towin_x[i]:=0;
  towin_o[i]:=0;
  m[i,r].o:=0;
  m[i,r].x:=0;
  m[i,r].e:=0;
  m[i,c].o:=0;
  m[i,c].x:=0;
  m[i,c].e:=0;
  m[1,d].o:=0;
  m[1,d].x:=0;
  m[1,d].e:=0;
  m[2,d].o:=0;
  m[2,d].x:=0;
  m[2,d].e:=0;
 end;
end;


procedure set_field;

begin
 step:=1;
 for i:=1 to 3 do
 begin
  for j:=1 to 3 do
  begin
   case (a[i][j]) of
    'O': inc (m[i,r].o);
    'X': inc (m[i,r].x);
    '#':
    begin
     inc(m[i,r].e);
     emp[step].i:=i;
     emp[step].j:=j;
     inc(step);
    end;
   end;
  end;
 end;
 for i:=1 to 3 do
 begin
  for j:=1 to 3 do
  begin
   case (a[j][i]) of
    'O': inc (m[i,c].o);
    'X': inc (m[i,c].x);
    '#': inc(m[i,c].e);
   end;
  end;
 end;

 for i:=1 to 3 do
  case (a[i][i]) of
   'O': inc (m[1,d].o);
   'X': inc (m[1,d].x);
   '#': inc(m[1,d].e);
  end;

 for i:=1 to 3 do
  case (a[i][4-i]) of
   'O': inc (m[2,d].o);
   'X': inc (m[2,d].x);
   '#': inc(m[2,d].e);   
  end;

  for i:=1 to step-1 do
  begin
   k:=emp[i].i;
   l:=emp[i].j;
   // row
   if m[k,r].o=2 then win_o[i]:=true;
   if m[k,r].x=2  then win_x[i]:=true;
   if (m[k,r].o=1) and (m[k,r].e=2) then inc(towin_o[i]);
   if (m[k,r].x=1) and (m[k,r].e=2) then inc(towin_x[i]);
   // column
   if m[l,c].o=2 then win_o[i]:=true;
   if m[l,c].x=2  then win_x[i]:=true;
   if (m[l,c].o=1) and (m[l,c].e=2) then inc(towin_o[i]);
   if (m[l,c].x=1) and (m[l,c].e=2) then inc(towin_x[i]);
   // main diag
   if l=k then
   begin
    if m[1,d].o=2 then win_o[i]:=true;
    if m[1,d].x=2  then win_x[i]:=true;
    if (m[1,d].o=1) and (m[1,d].e=2) then inc(towin_o[i]);
    if (m[1,d].x=1) and (m[1,d].e=2) then inc(towin_x[i]);
   end;
   // second diag
   if l=4-k then
   begin
    if m[2,d].o=2 then win_o[i]:=true;
    if m[2,d].x=2  then win_x[i]:=true;
    if (m[2,d].o=1) and (m[2,d].e=2) then inc(towin_o[i]);
    if (m[2,d].x=1) and (m[2,d].e=2) then inc(towin_x[i]);
   end;
  end;

end;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1195.in');
 reset(input);
 assign(output, 'T1195.out');
 rewrite(output);
{$ENDIF}
 for i:=1 to 3 do
 begin
  for j:=1 to 3 do
   read (a[i,j]);
  readln;
 end;

 set0;
 set_field;


 //crosses' turn

 for i:=1 to step-1 do
  if win_x[i] then
  begin
   writeln (cross);
   goto 1;
  end;
  
 for i:=1 to step-1 do
  if win_o[i] then
  begin
   a[emp[i].i,emp[i].j]:='X';
   set0;
   set_field;
   goto 2;
  end;

 max:=0;
 toset:=0;
 for i:=1 to step-1 do
 begin
  if towin_x[i]>max then
  begin
   max:=towin_x[i];
   toset:=i;
  end;
 end;
 a[emp[toset].i,emp[toset].j]:='X';
 set0;
 set_field;


 2: // ouths' turn

 for i:=1 to step-1 do
  if win_o[i] then
  begin
   writeln (outh);
   goto 1;
  end;

 for i:=1 to step-1 do
  if win_x[i] then
  begin
   a[emp[i].i,emp[i].j]:='O';
   set0;
   set_field;
   goto 3;
  end;

 max:=0;
 toset:=0;
 for i:=1 to step-1 do
 begin
  if towin_o[i]>max then
  begin
   max:=towin_o[i];
   toset:=i;
  end;
 end;
 a[emp[toset].i,emp[toset].j]:='O';
 set0;
 set_field;

 3: // crosses' turn
  for i:=1 to step-1 do
  if win_x[i] then
  begin
   writeln (cross);
   goto 1;
  end;
 writeln(dr);
 1:;
{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
