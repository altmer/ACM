#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector <vector <int> > T;
vector <bool> color;
vector <int> D, A;
queue <int> q;
double ans=1000000;

void init (void)
{
	scanf ("%d%d", &n, &m);
	T.resize(n);
	color.resize(n);
	D.resize(n);
}
void make_tree (void)
{
	for (int u=0; u<n; ++u)
	{
		T[u].push_back((u+1)%n);

		T[u].push_back((u+n-1)%n);
		
		if (u+m<=n-1)
			T[u].push_back(u+m);

		if (u-m>=0)
			T[u].push_back(u-m);
	}
}

int BFS(int u)
{
	int sum=0;
	color.clear();
	color.resize(n);
	D.clear();
	D.resize(n);
	q.push (u);
	color[u]=true;
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (int i=0; i<T[u].size(); ++i)
		{
			if (!color[T[u][i]])
			{
				D[T[u][i]]=D[u]+1;
				sum+=D[T[u][i]];
				color[T[u][i]]=true;
				q.push(T[u][i]);
			}
		}
	}
	return sum;
}
void solve (void)
{
	int cur;
	for (int i=0; i<=(n/2); ++i)
	{
		cur=BFS(i);
		if (cur<ans)
		{
			D.swap(A);
			ans=cur;
		}
	}
	ans/=n;
}
void print (void)
{
	printf ("Mean = %.2lf\n", ans);
	for (int i=0; i<n; ++i)
	{
		printf ("%d ", A[i]);
		if ((i+1)%m==0)
			printf ("\n");
	}
}
int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1400.in", "r", stdin);
	freopen ("T1400.out", "w", stdout);
#endif

	init();
	make_tree();
	solve();
	print();

	return 0;
}