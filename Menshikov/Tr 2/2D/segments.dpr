program segments;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type point = record
      x, y : integer;
      end;

     vector = record
      x, y : integer;
      st,en : point;
     end;

var A, B, C, D : point;
    p : array [1..12] of vector;
    i:integer;
    res:boolean;

function VP (v1, v2 : vector) : integer;

begin
 result:=v1.x*v2.y-v2.x*v1.y;
end;

function min (a, b : integer) : integer;

begin
 if a<b then result:=a else result:=b;
end;

function max (a, b : integer) : integer;

begin
 if a>b then result:=a else result:=b;
end;


begin
 assign (input,'segments.in');
 reset (input);
 assign (output,'segments.out');
 rewrite(output);

 readln (A.x, A.y);
 readln (B.x, B.y);
 readln (C.x, C.y);
 readln (D.x, D.y);

 p[1].x:=B.x-A.x;
 p[1].y:=B.y-A.y;
 p[1].st:=A;
 p[1].en:=B;
 p[2].x:=C.x-A.x;
 p[2].y:=C.y-A.y;
 p[2].st:=A;
 p[2].en:=C;
 p[3].x:=D.x-A.x;
 p[3].y:=D.y-A.y;
 p[3].st:=A;
 p[3].en:=D;

 p[4].x:=A.x-B.x;
 p[4].y:=A.y-B.y;
 p[4].st:=B;
 p[4].en:=A;
 p[5].x:=C.x-B.x;
 p[5].y:=C.y-B.y;
 p[5].st:=B;
 p[5].en:=C;
 p[6].x:=D.x-B.x;
 p[6].y:=D.y-B.y;
 p[6].st:=B;
 p[6].en:=D;

 p[7].x:=D.x-C.x;
 p[7].y:=D.y-C.y;
 p[7].st:=C;
 p[7].en:=D;
 p[8].x:=A.x-C.x;
 p[8].y:=A.y-C.y;
 p[8].st:=C;
 p[8].en:=A;
 p[9].x:=B.x-C.x;
 p[9].y:=B.y-C.y;
 p[9].st:=C;
 p[9].en:=B;

 p[10].x:=C.x-D.x;
 p[10].y:=C.y-D.y;
 p[10].st:=D;
 p[10].en:=C;
 p[11].x:=A.x-D.x;
 p[11].y:=A.y-D.y;
 p[11].st:=D;
 p[11].en:=A;
 p[12].x:=B.x-D.x;
 p[12].y:=B.y-D.y;
 p[12].st:=D;
 p[12].en:=B;

 i:=1;
 while i<=12 do
 begin
  if VP(p[i],p[i+1])*VP(p[i],p[i+2])<0 then res:=true
   else if VP(p[i],p[i+1])*VP(p[i],p[i+2])=0 then
   begin
    if VP(p[i],p[i+1])=0 then
    begin
     if (p[i+1].en.x>=min(p[i].st.x,p[i].en.x)) and (p[i+1].en.x<=max(p[i].st.x,p[i].en.x))
      and (p[i+1].en.y>=min(p[i].st.y,p[i].en.y)) and (p[i+1].en.y<=max(p[i].st.y,p[i].en.y))
       then res:=true else begin res:=false; break; end;
    end;

    if VP(p[i],p[i+2])=0 then
    begin
     if (p[i+2].en.x>=min(p[i].st.x,p[i].en.x)) and (p[i+2].en.x<=max(p[i].st.x,p[i].en.x))
      and (p[i+2].en.y>=min(p[i].st.y,p[i].en.y)) and (p[i+2].en.y<=max(p[i].st.y,p[i].en.y))
       then res:=true else begin res:=false; break; end;
    end;
   end
    else
    begin
     res:=false;
     break;
    end;
  inc(i,3);
 end;

 if res then writeln ('Yes') else writeln ('No');

 close (input);
 close (output);
end.
