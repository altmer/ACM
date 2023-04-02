#include<iostream>
#include<stdio.h>
using namespace std;
__int64 n,a,k;
void work ()
{
__int64 i,na,x;
if (n<316227) x=2*n; else x=316227;
for (i=x;i>=1;i--)
{
na=2*n+i-i*i;
if (((na%(2*i))==0)&&(na>0))
{
na=na/(2*i);
a=na;
k=i;
break;
}
}
}
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen ("T1120.in", "r", stdin);
	freopen ("T1120.out", "w", stdout);
#endif
cin>>n;
work ();
cout<<a<<" "<<k;
return 0;
}