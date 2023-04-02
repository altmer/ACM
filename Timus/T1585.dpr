program T1585;
{$apptype console}

uses
  sysutils;

const e = 'Emperor Penguin';
      l = 'Little Penguin';
      m = 'Macaroni Penguin';

var i, n : integer;
    en, mn, ln : integer;
    ch : char;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1585.in');
 reset(input);
 assign(output, 'T1585.out');
 rewrite(output);
{$ENDIF}

 en:=0;
 mn:=0;
 ln:=0;  
 readln(n);
 for i:=1 to n do
 begin
  readln (ch);
  case ch of
   'E': inc (en);
   'M': inc (mn);
   'L': inc (ln);
  end;
 end;

 if en>mn then
 begin
  if en>ln then writeln (e) else writeln (l);
 end

 else
 begin
  if mn>ln then writeln (m) else writeln (l);
 end;



{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
