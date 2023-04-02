program Abc;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type bug = record
      meet, gend : boolean;
      end;

var sc, nsc, n, m, i : integer;
    mas : array [1..2000] of bug;
    a, b : integer;
    res : boolean;

begin
 assign (input,'knights.in');
 assign (output,'knights.out');
 reset(input);
 rewrite(output);

 writeln ('b');

 close(input);
 close(output);
end.
