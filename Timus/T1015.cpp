#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int A[30][6] = {
	{1, 2, 3, 4, 5, 6},
{1, 2, 3, 4, 6, 5},
{1, 2, 3, 5, 4, 6},
{1, 2, 3, 5, 6, 4},
{1, 2, 3, 6, 4, 5},
{1, 2, 3, 6, 5, 4},
{1, 3, 2, 4, 5, 6},
{1, 3, 2, 4, 6, 5},
{1, 3, 2, 5, 4, 6},
{1, 3, 2, 5, 6, 4},
{1, 3, 2, 6, 4, 5},
{1, 3, 2, 6, 5, 4},
{1, 4, 2, 3, 5, 6},
{1, 4, 2, 3, 6, 5},
{1, 4, 2, 5, 3, 6},
{1, 4, 2, 5, 6, 3},
{1, 4, 2, 6, 3, 5},
{1, 4, 2, 6, 5, 3},
{1, 5, 2, 3, 4, 6},
{1, 5, 2, 3, 6, 4},
{1, 5, 2, 4, 3, 6},
{1, 5, 2, 4, 6, 3},
{1, 5, 2, 6, 3, 4},
{1, 5, 2, 6, 4, 3},
{1, 6, 2, 3, 4, 5},
{1, 6, 2, 3, 5, 4},
{1, 6, 2, 4, 3, 5},
{1, 6, 2, 4, 5, 3},
{1, 6, 2, 5, 3, 4},
{1, 6, 2, 5, 4, 3}
};

vector <vector <int> > S (30);
vector <int> v (6);
vector <vector <int> > sch (30);
int n;

void init (void)
{
	for (int i=0; i<S.size(); ++i)
	{
		for (int j=0; j<6; ++j)
		{
			S[i].push_back(A[i][j]);
		}
	}
}

void left (vector <int> &a)
{
	int temp=a[0];
	a[0]=a[3];
	a[3]=a[1];
	a[1]=a[5];
	a[5]=temp;
}

void right (vector <int> &a)
{
	int temp=a[0];
	a[0]=a[5];
	a[5]=a[1];
	a[1]=a[3];
	a[3]=temp;
}

void up (vector <int> &a)
{
	int temp=a[2];
	a[2]=a[3];
	a[3]=a[4];
	a[4]=a[5];
	a[5]=temp;
}


void CW (vector <int> &a)
{
	int temp=a[0];
	a[0]=a[4];
	a[4]=a[1];
	a[1]=a[2];
	a[2]=temp;
}
void CCW (vector <int> &a)
{
	int temp=a[0];
	a[0]=a[2];
	a[2]=a[1];
	a[1]=a[4];
	a[4]=temp;
}


void turn (vector <int> &a)
{
	if (a[0]!=1)
	{
		if (a[1]==1)
		{
			left(a);
			left(a);
		}
		else if (a[2]==1)
		{
			CCW(a);
		}
		else if (a[3]==1)
		{
			left(a);
		}
		else if (a[4]==1)
		{
			CW(a);
		}
		else if (a[5]==1)
		{
			right(a);
		}
	}
}

int find (vector <int> &a)
{
	for (int i=0; i<S.size(); ++i)
	{
		if (S[i]==a)
			return i;
	}
	return -1;
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1015.in", "r", stdin);
	freopen ("T1015.out", "w", stdout);
#endif

	init ();
	scanf ("%d", &n);
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<6; ++j)
		{
			scanf ("%d", &v[j]);
		}
		turn (v);
		int ans;
		for (int k=0; k<4; ++k)
		{
			ans=find(v);
			if (ans!=-1)
			{
				sch[ans].push_back(i+1);
				break;
			}
			up(v);
		}
	}

	sort (sch.begin(), sch.end());

	int k=0;
	while (sch[k].empty())
		++k;

	printf ("%d\n", 30-k);
	for (int i=k; i<30; ++i)
	{
		for (int j=0; j<sch[i].size(); ++j)
		{
			printf ("%d ", sch[i][j]);
		}
		printf ("\n");
	}

	return 0;
}