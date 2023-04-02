#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int M=2000000000;
int A[100][100], dist[100], par[100];
bool color [100];
int n, m, len;
queue <int> q;
vector <int> route;

void BFS (int beg)
{
	int u;

	q.push(beg);
	while (!q.empty())
	{
		u=q.front();
		color[u]=true;
		q.pop();
		for (int v=0; v<n; ++v)
		{
			if (dist[u]+A[u][v]<len)
			{
			if (A[u][v] && !color[v])
			{
				q.push(v);
				color[v]=true;
				dist[v]=dist[u]+A[u][v];
				par[v]=u;
			}
			else if (A[u][v] && color[v] && dist[v]>dist[u]+A[u][v])
			{
				q.push(v);
				dist[v]=dist[u]+A[u][v];	
				par[v]=u;
			}
			}
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1004.in", "r", stdin);
	freopen ("T1004.out", "w", stdout);
#endif

	do 
	{
		len=M;
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				A[i][j]=0;
		route.clear();
		cin >> n >> m;

				
		for (int i=0; i<m; ++i)
		{
			int k, l, s;
			cin >> k >> l >> s;
			A[k-1][l-1]=s;
			A[l-1][k-1]=s;
		}

		for (int i=0; i<n; ++i)
		{

			for (int l=0; l<n; ++l)
			{
				if (A[i][l])
				{
					for (int j=0; j<n; ++j)
					{
						dist[j]=0;
						par[j]=0;
						color[j]=false;
					}

					int temp=A[i][l];
					A[i][l]=0;
					A[l][i]=0;
					BFS (i);
					A[i][l]=temp;
					A[l][i]=temp;

					if (dist[l]&&dist[l]+temp<len)
					{
						int v;
						route.clear();
						len=dist[l]+temp;
						v=l;
						do 
						{
							route.push_back(v);
							v=par[v];
						}
						while (v!=i);
						route.push_back(i);
					}
				}
			}
		}

		if (len!=M && n!=-1 && route.size()>2)
		{
			for (int i=0; i<route.size(); ++i)
				cout << route[i]+1 << " ";
			cout << "\n";
		}
		else if (n!=-1)
			cout << "No solution.\n";
		
	}
	while (n!=-1);

	return 0;
}