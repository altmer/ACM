#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
using namespace std;

struct sign
{
	int num, id;
	bool operator < (sign a)
	{
		return num>a.num;
	}
};

vector <sign> v;
int k, p, s, pid;
bool fin, does;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1604.in", "r", stdin);
	freopen ("T1604.out", "w", stdout);
#endif

	scanf ("%d", &k);
	v.resize(k);

	for (int i=0; i<k; ++i)
	{
		scanf ("%d", &v[i].num);
		v[i].id=i+1;
		s+=v[i].num;
	}

	sort(v.begin(), v.end());
	printf ("%d ", v[0].id);
	--v[0].num;
	--s;
	p=v[0].id;
	pid=0;

	while (s>0)
	{
		int i=pid+1;
		while (i<v.size()-1 && v[i].num>v[pid].num)
			++i;

		if (i<v.size())
		{
			if (v[i].num<=v[pid].num)
				--i;

			sign t=v[i];
			v[i]=v[pid];
			v[pid]=t;
		}
		
		does=false;
		for (int i=0; i<v.size(); ++i)
		{
			if (v[i].num!=0 && v[i].id!=p)
			{
				does=true;
				p=v[i].id;
				printf ("%d ", v[i].id);
				v[i].num--;
				s--;
				pid=i;
				break;
			}
			else if (v[i].num==0)
				break;
		}

		if(!does)
		{
			for (int i=0; i<v[0].num; ++i)
			{
				printf ("%d ", v[0].id);
			}
			s=0;
		}
	}

	return 0;
}