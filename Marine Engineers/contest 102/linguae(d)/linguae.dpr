program linguae;

{$APPTYPE CONSOLE}
uses
  SysUtils;

type
  number = record
   one, wto, there : integer;
   end;


var ans : array [1..50000] of integer;
    kyrs : array [1..50000] of number;

    i,j,n,temp : integer;



Begin
  assign (input,'linguae.in');
  assign (output,'linguae.out');
  reset(input);
  rewrite(output);

  readln (n);
  for i:=1 to n do
     readln(kyrs[i].one,kyrs[i].wto,kyrs[i].there);


   for i:=1 to (n+3) do
    begin


      temp:=kyrs[i].one + ans[i];
      if (temp<ans[i+1]) or (ans[i+1]=0) then ans[i+1]:=temp;
      temp:=kyrs[i].wto + ans[i];
      if (temp<ans[i+2]) or (ans[i+2]=0)then ans[i+2]:=temp;
      if (ans[i+2]<ans[i+1]) then ans[i+1]:=temp;
      temp:=kyrs[i].there + ans[i];
      if (temp<ans[i+3]) or (ans[i+3]=0)then ans[i+3]:=temp;
      if (ans[i+3]<ans[i+2]) then ans[i+2]:=temp;
      if (ans[i+3]<ans[i+1]) then ans[i+1]:=temp;
 
    end;
 if ans[n+2]>ans[n+3] then ans[n+2]:=ans[n+3];
  if ans[n+1]>ans[n+2] then ans[n+1]:=ans[n+2];
  writeln(ans[n+1]);



  close(input);
  close(output);
end.
