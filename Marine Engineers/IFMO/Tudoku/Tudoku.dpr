program Kick;

{$APPTYPE CONSOLE}
uses
  SysUtils;

const s=45;

var i,j,n,k,sum,l : integer;
    line:string;
    sud, WB : array[0..8,0..8] of integer;
    row, col, block:array[0..8,1..2] of byte;
    fin : boolean;

function WhichBlock (i, j : byte) : byte;
var s : integer;

begin
 s:=i div 3 + j div 3;
 case s of

 0: WhichBlock:=0;

 1: if i>2 then WhichBlock:=3 else WhichBlock:=1;

 2: if i<3 then WhichBlock:=2 else if i>5 then WhichBlock:=6 else WhichBlock:=4;

 3: if i>5 then WhichBlock:=7 else WhichBlock:=5;

 4: WhichBlock:=8;
 end;
end;



Begin
  assign (input,'tudoku.in');
  assign (output,'tudoku.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=0 to 8 do
   for j:=0 to 8 do
    WB[i,j]:=WhichBlock(i,j);
    
   for i:=1 to n do
   begin
    for j:=0 to 8 do
     begin
      readln(line);
      for k:=0 to 8 do
       begin
        sud[j,k]:=strtoint(copy(line,k+1,1));
        if sud[j,k]=0 then
         begin
          inc (row[j,2]); inc(col[k,2]); inc(block[WB[j,k],2]);
         end
         else
         begin
          row[j,1]:=row[j,1]+sud[j,k];
          col[k,1]:=col[k,1]+sud[j,k];
          block[WB[j,k],1]:=block[WB[j,k],1]+sud[j,k];
         end;
       end;
     end;

   while not fin do
   begin
    for j:=0 to 8 do
    begin

     if row[j,2]=1 then
     begin
      for k:=0 to 8 do if sud[j,k] = 0 then
      begin
       sud[j,k]:=s-row[j,1];
       dec(row[j,2]);
       dec(col[k,2]);
       dec(block[WB[j,k],2]);
       row[j,1]:=s;
       col[k,1]:=col[k,1]+sud[j,k];
       block[WB[j,k],1]:=block[WB[j,k],1]+sud[j,k];
      end;
     end;

     if col[j,2]=1 then
     begin
      for k:=0 to 8 do if sud[k,j] = 0 then
      begin
       sud[k,j]:=s-col[j,1];
       dec(row[k,2]);
       dec(col[j,2]);
       dec(block[WB[k,j],2]);
       col[j,1]:=s;
       row[k,1]:=row[k,1]+sud[k,j];
       block[WB[k,j],1]:=block[WB[k,j],1]+sud[k,j];
      end;
     end;

     if block[j,2]=1 then
     begin
      for k:=0 to 8 do
       for l:=0 to 8 do if (sud[k,l] = 0) and (WB[k,l]=j) then
       begin
        sud[k,l]:=s-block[j,1];
        dec(row[k,2]);
        dec(col[l,2]);
        dec(block[WB[k,l],2]);
        col[l,1]:=col[l,2]+sud[k,l];
        row[k,1]:=row[k,1]+sud[k,l];
        block[WB[k,j],1]:=s;
       end;
     end;

    end;
    for k:=0 to 8 do
     if row[k,2]<>0 then
      begin
       fin:=false;
       break;
      end

      else fin:=true;
   end;

  writeln ('Scenario #',i);
  for k:=0 to 8 do
  begin
   for l:=0 to 8 do
    write(sud[k,l]);
   writeln;
  end;
  writeln;
 end;

  close(input);
  close(output);
end.
