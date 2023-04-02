program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var line:string;
    line2:array[1..100] of integer;
    i,s:integer;

begin
     assign (input,'5.in');
     reset (input);
     assign (output,'5.out');
     rewrite(output);
     while not seekeof do
     readln (line);

     for i:=1 to length(line) do
     line2[i]:=strtoint(line[i]);

     if line[length(line)]='9' then
     begin
     line2[length(line)]:=0;
     for i:=(length(line)-1) downto 1 do
     if line2[i]=9 then line2[i]:=0
     else
     begin
     line2[i]:=strtoint(line[i])+1;
     break;
     end;
     end
     else line2[length(line)]:=strtoint(line[length(line)])+1;


     if line2[1]=0 then write('1');

     for i:= 1 to length(line)do
     write (line2[i]);
     {for s:=a to i do}
     {write (strtoint(line[s]));}


     close (input);
     close (output);

end.
