program Kick;

{$APPTYPE CONSOLE}
uses
  SysUtils;

var i,j,n,k,sum:integer;
    line1:string;
    sud:array[1..9,1..9] of integer;
    row,col,block:array[1..9,1..2];

function numer(a,b:integer);
 var a,b:integer
 begin


 end;


Begin
  assign (input,'tudoku.in');
  assign (output,'tudoku.out');
  reset(input);
  rewrite(output);
  readln(n);
   for i:=1 to n do
    for j:=1 to 9 do
     begin
      readln(line1);
      for k:=1 to 9 do
       begin
        sud[j,k]:=strtoint(line[k]);
        if sud[j,k]=0 then
         begin
          inc (row[j,2]); inc(col[k,2]); inc(
         end
         else
         row[j,1]:=row[j,1]+sud[j,k];
       end;

     end;






  close(input);
  close(output);
end.
