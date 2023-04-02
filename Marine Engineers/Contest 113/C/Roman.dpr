program corporate;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var rom : array [1..14] of string = ('O', 'I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M');
    des : array [1..14] of integer = (0, 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000);
    reg : array [0..9] of integer;
    ass : array [0..9] of boolean;
    s, cr : string;
    fin, add, ou : boolean;
    rinp, i, j, cur, ToPut, res : integer;

procedure enter;
var old : integer;

begin
  old:=0;
  while i<=length(s) do
  begin
  if (s[i]>'A') and (s[i]<'Z') then
   begin
    cr:='';
    cr:=cr+s[i];
    for j:=1 to 14 do
     if rom[j]=cr then
     begin
      Cur:=des[j];
      break;
     end;

    if cur<=old then Toput:=Toput+cur else toput:=toput-2*old+cur;
    old:=cur;     
    inc(i);
   end


   else if (s[i]>'0') and (s[i]<='9') then
   begin
    cr:='';
    while (s[i]>='0') and (s[i]<='9') do
    begin
     cr:=cr+s[i];
     inc(i);
    end;
    if ass [strtoint(cr)] then
    begin
     if add then ToPut:=ToPut+reg[strtoint(cr)] else ToPut:=ToPut-reg[strtoint(cr)];
    end
     else
     begin
      writeln ('Error');
      ou:=false;
      break;
     end;
   end

   else if (s[i]='+') then
   begin
    cr:='';
    if add then res:=res+ToPut else res:=res-ToPut;
    if (res<0) or (res>10000) then
    begin
     writeln ('Error');
     ou:=false;
     break;
    end;
    add:=true;
    inc(i);
    ToPut:=0;
   end

   else
   begin
    cr:='';
    if add then res:=res+ToPut else res:=res-ToPut;
    if (res<0) or (res>10000) then
    begin
     writeln ('Error');
     ou:=false;
     break;
    end;
    add:=false;
    ToPut:=0;
    inc (i);
   end;
  end;
 if add then res:=res+ToPut else res:=res-ToPut;
 if (res<0) or (res>10000) then
 begin
  writeln ('Error');
  ou:=false;
 end
 else
  reg[rinp]:=res;
  ass[rinp]:=true;
end;

procedure outp;
var ans, i, j : integer;

begin
 write (rinp, '=');
 ans:=reg[rinp];
 i:=14;
 if reg[rinp]=0 then write(rom[1]);
 while (i>0) and (ans>0) do
 begin
  if ans div des[i]<>0 then
  begin
   for j:=1 to ans div des[i] do
    write (rom[i]);
   ans:=ans-des[i]*(ans div des[i]); 
  end

  else dec(i);
 end;
 writeln; 
end;

begin
 assign (input,'input.txt');
 assign (output,'output.txt');
 reset(input);
 rewrite(output);

 while not fin do
 begin
  cr:='';
  toput:=0;
  res:=0;
  readln (s);
  i:=0;
  if s='QUIT' then
  begin
   writeln ('Bye');
   fin := true
  end

  else if s='RESET' then
  begin
   writeln ('Ready');
   for i:=1 to 10 do reg[i]:=0;
  end

  else
  begin
   ou:=true;
   add:=true;
   i:=1;
   while (s[i]>='0') and (s[i]<='9') do
   begin
    cr:=cr+s[i];
    inc(i);
   end;
   rinp:=strtoint(cr);
   cr:='';
   inc(i);
   ToPut:=0;
   res:=0;
   Enter;
   if ou then outp;
  end;
 end; 
 
 close(input);
 close(output);
end.
