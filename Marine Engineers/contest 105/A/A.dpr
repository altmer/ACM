program A;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const none = 0;
      white = 1;
      black = 2;

var gr : array [1..8, 'a'..'h'] of integer;
    s : string;
    dx : array [1..4] of integer = [1,  1,  -1,  -1];
    dy : array [1..4] of integer = [1, -1,   1,  -1];
    i : integer;
    r1, r2, rc : integer;
    c1, c2, cc : char;
    nb, nw : integer;

begin
 assign (input,'A.in');
 assign (output,'A.out');
 reset(input);
 rewrite(output);

 nb:=12;
 nw:=12

 gr [1, 'a']:=white;
 gr [3, 'a']:=white;
 gr [2, 'b']:=white;
 gr [1, 'c']:=white;
 gr [3, 'c']:=white;
 gr [2, 'd']:=white;
 gr [1, 'e']:=white;
 gr [3, 'e']:=white;
 gr [2, 'f']:=white;
 gr [1, 'g']:=white;
 gr [3, 'g']:=white;
 gr [2, 'h']:=white;

 gr [7, 'a']:=black;
 gr [6, 'b']:=black;
 gr [8, 'b']:=black;
 gr [7, 'c']:=black;
 gr [6, 'd']:=black;
 gr [8, 'd']:=black;
 gr [7, 'e']:=black;
 gr [6, 'f']:=black;
 gr [8, 'f']:=black;
 gr [7, 'g']:=black;
 gr [6, 'h']:=black;
 gr [8, 'h']:=black;


 while not seekeof do
 begin
  readln (s);
  i:=1;
  repeat
   inc (i);
  until (s[i]>='a') and (s[i]<='z');
  // white turn
  c1:=s[i];
  r1:=ord(s[i+1])-ord('0');
  c2:=s[i+3];
  r2:=ord(s[i+4])-ord('0');

  if (abs (r2-r1)=1) and (abs (ord(c2)-ord(c1))=1) then
  // empty turn
  begin
   grid [r1, c1]:=none;
   grid [r2, c2]:=white;
  end

  else
  // sophisticated turn
  begin
   // all possible eatings
   rc:=r1;
   cc:=c1;
   repeat
    for i:=1 to 4 do
    begin
     if grid [r1+dx, chr (ord(c1)+dy)]=black then
      begin
       rc:=r1+2*dx;
       cc:=chr(ord(c1)+2*dy);
       grid [r1+dx, chr (ord(c1)+dy)]:=none;
       dec (nb);
       fin:=false;
       break;
      end
     else fin:=true;
    end;

    if (rc=r2) and (cc=c2) then fin:=true;
   until fin=true;

   if (rc<>r2) and (cc<>c2) then
   // queen turn
   begin
    if (abs(r2-r1) = abs(ord(c2)-ord(c1))) then
    begin
     for i:=1 to abs(r2-r1)
    end;
   end;
  end;

  i:=i+6;
  c1:=s[i];
  r1:=ord(s[i+1])-ord('0');
  c2:=s[i+3];
  r2:=ord(s[i+4])-ord('0');
 end;

 close(input);
 close(output);
end.
