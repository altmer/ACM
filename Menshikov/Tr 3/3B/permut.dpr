program permutx;

{$APPTYPE CONSOLE}

uses
  SysUtils;


var
 s : string;
 count : array [char] of byte;
 c : char;
 i, n : integer;

procedure permut (k : integer);
var c : char;

begin
 if k = n + 1 then writeln (s)

 else
 begin
  for c:=#0 to #255 do
   if count[c]<>0 then
   begin
    s[k]:=c;
    dec(count[c]);
    permut(k+1);
    inc(count[c]);
   end;
 end; 
end;

begin
 assign (input,'permut.in');
 reset (input);
 assign (output,'permut.out');
 rewrite(output);

 readln (s);
 n:=length(s);
 for c:=#0 to #255 do count[c]:=0;
 for i:=1 to length(s) do inc (count[s[i]]);

 permut (1);

 close (input);
 close (output);
end.
