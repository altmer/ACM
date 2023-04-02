#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;
int a[1000];
set <int> d;
vector <int> v;
struct str
{
	int a;
	char c;
	bool operator < (str &b)
	{
		if (a==b.a)
			return c<b.c;
		return a<b.a;
	}
};

str s[1000];
bool gtr (int a,int b)
{
	return a>b;
}
bool ret (str a, str b)
{
	if (a.a==b.a)
		return a.c<b.c;
	return a.a<b.a;
}
int main (void)
{
	 
	for (int i=0;i<=999;++i)
	{
		a[i]=rand()%30;
		s[i].a=rand();
		s[i].c=rand()%26+'a';
	}
	sort(a,a+1000,gtr);
	
	printf("Massive S:\n %I64d\\%05d %.3lf%%", __int64(s[1].a), s[2].a, double (s[3].a));
	char number[100];
	sort(number+2,number+10);
	sprintf(&number[2],"hello %lf",3.1415);
	if (s[2]<s[3])
		cout << s[2].a;
	v.push_back(12);
	v.push_back(34);
	v.push_back(324);
	sort(v.begin(),v.end(), gtr);
	d.insert(45);
	if(d.find(25)==d.end())d.insert(25);
	return 0;
	
}
