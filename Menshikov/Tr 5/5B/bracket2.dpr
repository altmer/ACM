program bracket2;
{$APPTYPE CONSOLE}
uses
  SysUtils;

var ans : array [0..14] of char;
    stack : array [0..14] of char;
    n : integer;

procedure answer;
var i : integer;

begin
 for i:=1 to n do
  write (ans[i]);
 writeln;
end;

procedure permut (k, ToPut, sp : integer; s : array of char);

begin
 if k=n+1 then
 begin
  answer;
  exit;
 end;

 if ToPut>0 then
 begin
  ans[k]:='(';
  s[sp+1]:='(';
  permut (k+1, Toput-1, sp+1, s);

  ans[k]:='[';
  s[sp+1]:='[';
  permut (k+1, Toput-1, sp+1, s);
 end;

 if sp<>0 then
 begin
  if s[sp]='(' then
  begin
   ans[k]:=')';
   permut (k+1, toput, sp-1, s);
  end

  else
  begin
   ans[k]:=']';
   permut (k+1, toput, sp-1, s);
  end
 end;
end;     

begin
 assign(input,'bracket2.in');
 reset (input);
 assign(output,'bracket2.out');
 rewrite(output);

 readln (n);

 permut (1, n div 2, 0, stack);

 close(input);
 close(output);
end.
