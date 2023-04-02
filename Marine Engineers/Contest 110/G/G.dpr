program D2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var n, i, k : integer;
    a, b, ca, cb : int64;
begin
 assign (input,'diophantus.in');
 assign (output,'diophantus.out');
 reset(input);
 rewrite(output);
 a:=1;
 b:=12;

 for i:=1 to 10000 do
 begin
  ca:=a*(i+1);
  cb:=b*(i+1);
  for k:=1 to ca-1 do
  begin
   n:=ca-k;
   if (cb mod n = 0) and (cb mod k = 0) then
    write ('1/',cb div n, '+', '1/', cb div k, ' '); 
  end;
  writeln;
 end;

 close(input);
 close(output);
end.
