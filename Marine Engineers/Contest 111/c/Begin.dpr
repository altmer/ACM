program F;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var max,min,i,j,k,a,n:integer;



begin
  
  assign(input,'parking.in');
  reset(input);
  assign(output,'parking.out');
  rewrite(output);
   readln (n);
    for i:=1 to n do
     begin
      min:=1000;
      max:=-1000;
      readln(k);
       for j:=1 to k do
        begin
         read(a);
         if a>max then max:=a;
         if a<min then min:=a;
        end;
        readln;
      writeln((max-min)*2);
    end;






  close(input);
  close(output);

end.
