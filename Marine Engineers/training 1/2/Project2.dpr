program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var line:string;
    i:integer;
    inword:boolean;

begin
     assign (input,'2.in');
     reset (input);
     assign (output,'2.out');
     rewrite(output);
     while not seekeof do
     read (line);
     inword:=true;
     for i:=1 to length(line) do
     begin
     if (line[i]<>#32) and (line[i]<>#9) then
     begin
     if inword=false then
     writeln;
     inword:=true;
     write(line[i]);
     end
     else inword:=false;
     end;
     close (input);
     close (output);

end.
