program d;

{$APPTYPE CONSOLE}

uses SysUtils;

type trend = record
      name : string;
      value : integer;
      end;

var s, word, s1 : string;
    ans : array [1..40] of char;
    i, j, k, l, num : integer;
    digit : array [0..27] of trend;
    exe : boolean;

begin
 assign (input,'I.in');
 assign (output,'I.out');
 reset(input);
 rewrite(output);
 while not seekeof do
 begin

 digit[0].name:='zero';
 digit[0].value:=0;
 digit[1].name:='one';
 digit[1].value:=1;
 digit[2].name:='two';
 digit[2].value:=2;
 digit[3].name:='three';
 digit[3].value:=3;
 digit[4].name:='four';
 digit[4].value:=4;
 digit[5].name:='five';
 digit[5].value:=5;
 digit[6].name:='six';
 digit[6].value:=6;
 digit[7].name:='seven';
 digit[7].value:=7;
 digit[8].name:='eight';
 digit[8].value:=8;
 digit[9].name:='nine';
 digit[9].value:=9;
 digit[10].name:='ten';
 digit[10].value:=10;
 digit[11].name:='eleven';
 digit[11].value:=11;
 digit[12].name:='twelve';
 digit[12].value:=12;
 digit[13].name:='thirteen';
 digit[13].value:=13;
 digit[14].name:='fourteen';
 digit[14].value:=14;
 digit[15].name:='fifteen';
 digit[15].value:=15;
 digit[16].name:='sixteen';
 digit[16].value:=16;
 digit[17].name:='seventeen';
 digit[17].value:=17;
 digit[18].name:='eighteen';
 digit[18].value:=18;
 digit[19].name:='nineteen';
 digit[19].value:=19;
 digit[20].name:='twenty';
 digit[20].value:=20;
 digit[21].name:='thirty';
 digit[21].value:=30;
 digit[22].name:='forty';
 digit[22].value:=40;
 digit[23].name:='fifty';
 digit[23].value:=50;
 digit[24].name:='sixty';
 digit[24].value:=60;
 digit[25].name:='seventy';
 digit[25].value:=70;
 digit[26].name:='eighty';
 digit[26].value:=80;
 digit[27].name:='ninety';
 digit[27].value:=90;



 readln(s);
 k:=0;
 i:=length(s);
 num:=1;

 while i > 0 do
  begin
   exe:=false;
   j := i;
   while (s[j]<> ' ') and (j<>0) do dec(j);
   word := copy(s,j+1,i-j);
   for i:=0 to 27 do
   begin
    if digit [i].name = word then
    begin
     exe:=true;
     s1:=inttostr(digit[i].value);
     if s1[length(s1)]='0' then
      if k<>0 then delete(s1,length(s1), 1); 
     for l:=length(s1) downto 1 do
     begin
      ans[num]:=s1[l];
      inc(num);
      inc (k);
     end;
     break;
    end;
   end;

   if not exe then
    if word = 'hundred' then
      for i:=1 to 2-k do
      begin
       ans[num]:='0';
       inc(num);
      end

    else if word = 'thousand' then
      begin
      for i:=1 to 4-num do
      begin
       ans[num]:='0';
       inc(num);
      end;
      k:=0;
      end

    else if word = 'million' then
    begin
      for i:=1 to 7-num do
      begin
       ans[num]:='0';
       inc(num);
      end;
      k:=0;
    end

     else if word = 'negative' then
      begin
       ans[num]:='-';
       inc(num);
      end;
    i:=j-1;
  end;

 for i:=num-1 downto 1 do write (ans[i]);
 end;

 close(input);
 close(output);
end.
