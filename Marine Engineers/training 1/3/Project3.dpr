program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var line:string;
    i:integer;


begin
     assign (input,'3.in');
     reset (input);
     assign (output,'3.out');
     rewrite(output);
     while not eof do
     readln (line);
     for i:=1 to length(line) do
     begin
     write(line[i]);
     if (i mod 5)=0 then
     writeln;
     end;
   
     close (input);
     close (output);

end.
