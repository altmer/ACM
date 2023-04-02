program Phone;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var i,j,k,n,l,m,t:integer;
    a:array[0..10000] of string;
    w:boolean;
    line:string;


procedure QS (var a : array of string;  l, r : integer);
var mid, t : string;
    k, m : integer;

begin
 k:=l;
 m:=r;
 mid:=a[(k+m) div 2];
 repeat
 while  a[k]<mid do inc (k);
 while  a[m]>mid do dec (m);
 if k<=m then
 begin
  t:=a[k];
  a[k]:=a[m];
  a[m]:=t;
  k:=k+1;
  m:=m-1;
 end;
 until k>m;

 if l<m then QS (a, l, m);
 if k<R then QS (a, k, R);
end;


begin
  assign(input,'phone.in');
  reset(input);
  assign(output,'phone.out');
  rewrite(output);
   readln (n);
    for i:=1 to n do
     begin
      w:=false;
      readln(k);
       for j:=0 to k-1 do
        begin
         readln(a[j]);
        end;
       QS(a,0,k-1);
       a[k]:='1';
       for l:=0 to k-1 do
        begin
         line:=a[l];
         m:=l+1;
         while (line[1]=a[m,1]) and (m<=k-1) do
          begin
           for t:=1 to length(line) do
            if line[t]=a[m,t] then w:=true else
            begin
             w:=false;
             break;
            end;
            if w then break;
            inc(m);
          end;
         if w then break;
        end;
      if not w then writeln('YES') else writeln('NO');
     end;



  close(input);
  close(output);

end.
