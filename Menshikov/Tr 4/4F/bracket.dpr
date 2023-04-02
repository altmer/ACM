{$apptype console}

uses
	sysutils;

var n, i : integer;
    ch, c : char;
    s : array [1..100000] of char;
    tail: integer = 1;

procedure push (U : char);

begin
 s[tail]:=u;
 inc(tail);
end;

function take : char;

begin
 dec (tail);
 take:=s[tail];
end;

function IsEmpty : boolean;

begin
 result:=(tail=1);
end;

begin
 assign (input,'bracket.in');
 reset (input);
 assign (output,'bracket.out');
 rewrite(output);

 readln (n);

 for i:=1 to n do
 begin
  read (ch);
  case ch of

  '(': push (ch);

  '[': push (ch);

  '{': push (ch);

  ')':
  begin
   c:=take;
   if c<>'(' then
   begin
    inc(tail);
    break;
   end;
  end;

  ']':
  begin
   c:=take;
   if c<>'[' then
   begin
    inc(tail);
    break;
   end;
  end;
  '}':
  begin
   c:=take;
   if c<>'{' then
   begin
    inc(tail);
    break;
   end;
  end;

  end;
 end;

 if not IsEmpty then writeln ('No') else writeln ('Yes'); 

 close (input);
 close (output);
end.



