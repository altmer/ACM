program T1502;
{$apptype console}

uses
  sysutils;

var n, i, j : integer;
    ans : int64; 

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1502.in');
 reset(input);
 assign(output, 'T1502.out');
 rewrite(output);
{$ENDIF}

 readln (n);
 ans:=0;
 for i:=0 to n do
  for j:=i to n do
   inc(ans,i+j);
 writeln(ans);
  
{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
