program c;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const free = 0;
      sep = 1;
      occ = 2;

var n, l, i, j, k, num : integer;
    ch : char;
    fin : boolean;
    a : array [0..300] of byte;

begin
 assign (input,'laundry.in');
 assign (output,'laundry.out');
 reset(input);
 rewrite(output);

 readln (n);
 readln (l);
 for k:=1 to l do
 begin
  readln (ch, num);
  if ch='D' then
  begin
   i:=0;
   repeat
    if a[i]=free then
    begin
     fin:=true;
     for j:=i to i+num-1 do
      if a[j mod n]<>free then
      begin
       fin:=false;
       break;
      end;
     i:=j mod n;
    end

    else
    begin
     inc (i);
     i:=i mod n;
    end;
   until (i=0) or (fin);
  end

  else
  begin

  end;
 end;

  
 close(input);
 close(output);
end.
