program T1023;
{$apptype console}

uses
  sysutils;

var n, k : integer;
    res : boolean;

begin
{$IFNDEF ONLINE_JUDGE}
 assign(input, 'T1023.in');
 reset(input);
 assign(output, 'T1023.out');
 rewrite(output);
{$ENDIF}

 read (n);
 res:=false;
 for k:=2 to round(sqrt(n)) do
  if (n mod (k+1))=0 then
  begin
   write (k);
   res:=true;
   break;
  end;

  if not res then
  begin
   if (n mod 2 = 0) and (((n div 2)-1)>=2) then write ((n div 2)-1)
    else write (n-1);
  end;



{$IFNDEF ONLINE_JUDGE}
 close(input);
 close(output);
{$ENDIF}
end.
