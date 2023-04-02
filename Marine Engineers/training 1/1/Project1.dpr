program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var a:integer;


begin
     assign (input,'1.in');
     reset (input);
     assign (output,'1.out');
     rewrite(output);
     while not seekeof do
     begin
     read (a);
     writeln (a);
     end;
     close (output);

end.
