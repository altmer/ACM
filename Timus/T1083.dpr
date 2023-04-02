program T1083;
{$apptype console}

uses
	sysutils;

var n, k, cur, fact : int64;
    ch : string;
    res : boolean;

begin
{$IFNDEF ONLINE_JUDGE}
   assign(input, 'T1083.in');
   reset(input);
   assign(output, 'T1083.out');
   rewrite(output);
{$ENDIF}

 read (n);
 read (ch);
 k:=length(ch)-1;

 cur:=n-k;
 fact:=n;
 while cur > 0 do
 begin
  fact:=fact*cur;
  cur:=cur-k;
 end;

 writeln (fact);

{$IFNDEF ONLINE_JUDGE}
   close(input);
   close(output);
{$ENDIF}
end.
