program D;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const e = 'Emperor Penguin';
      m = 'Macaroni Penguin';
      l = 'Little Penguin';

var a : array [1..1000] of string;
    ch : char;
    en, mn, ln, n, i : integer;

begin
 assign (input, 'input.txt');
 assign (output, 'output.txt');
 reset (input);
 rewrite (output);

 readln (n);
 for i:=1 to n do
 begin
  readln (ch);
  case ch of
  'E': inc(en);
  'M': inc(mn);
  'L': inc(ln);
  end;
 end;

 if en>mn then
 begin
  if en>ln then writeln(e) else writeln (l);
 end

 else
 begin
  if mn>ln then writeln(m) else writeln(l);
 end;


 close (input);
 close (output);
end.
