#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct coord
{
	int x, y;
	bool operator < (coord &c)
	{
		if (x==c.x)
			return y<c.y;
		return x<c.x;
	}
};

struct edge
{
	int vertex, dest;
};

const int top=1;
const int bottom=3;
const int rig=0;
const int lef=2;
char P[] = {'R', 'T', 'L', 'B'};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n;
string line;
vector <coord> draw;
vector <vector <edge> > list;
bool color[100];
queue <int> q;
int x0, y0;

void BFS (int u)
{
	q.push(u);
	color[u]=true;
	while (!q.empty())
	{
		u=q.front();
		q.pop();
		for (int i=rig; i<=bottom;++i)
			for (int j=0; j<list[u].size(); ++j)
			{
				int v=list[u][j].vertex;
				if (list[u][j].dest==i && !color[v])
				{
					printf ("%c", P[i]);
					color[v]=true;
					q.push(v);
				}
			}
		if (q.empty())
			printf (".");
		else
			printf(",\n");
	}
}

void One (void)
{
	list.resize(n);
	draw.resize(n);
	// input of vertexes
	for (int i=0; i<n; ++i)
	{
		scanf ("%d%d", &draw[i].x, &draw[i].y);
		for (int j=i-1; j>=0; --j)
		{
			if (draw[i].x-draw[j].x==1 && draw[i].y==draw[j].y)
			{
				edge E;
				E.vertex=j;
				E.dest=lef;
				list[i].push_back(E);
				E.vertex=i;
				E.dest=rig;
				list[j].push_back(E);
			}
			else if (draw[i].x==draw[j].x && draw[i].y-draw[j].y==1)
			{
				edge E;
				E.vertex=j;
				E.dest=bottom;
				list[i].push_back(E);
				E.vertex=i;
				E.dest=top;
				list[j].push_back(E);
			}
		}
	}
	printf ("%d %d\n", draw[0].x, draw[0].y);
	BFS(0);
}

void Second(void)
{
	coord u, v;
	while (getline(cin, line))
	{
		u=draw[q.front()];
		q.pop();
		for (int i=0; i<line.size(); ++i)
		{
			for (int j=rig; j<=bottom; ++j)
			{
				if (line[i]==P[j])
				{
					v.x=u.x+dx[j];
					v.y=u.y+dy[j];
					draw.push_back(v);
					q.push(draw.size()-1);
				}
			}
		}
	}

	sort (draw.begin(), draw.end());
	printf ("%d\n", draw.size());
	for (int i=0; i<draw.size(); ++i)
		printf ("%d %d\n", draw[i].x, draw[i].y);
}


int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1008.in", "r", stdin);
	freopen ("T1008.out", "w", stdout);
#endif

	getline (cin, line);
	bool first=true;
	int sep;
	for (int i=0; i<line.size(); ++i)
	{
		if (line[i]==' ')
		{
			first=false;
			sep=i;
			break;
		}
	}

	if (first)
	{
		char N[10];
		line.copy(N, line.size());
		n=atol(N);
		One();
	}

	else
	{
		char N[10];
		draw.resize(1);
		line.copy(N, sep);
		draw[0].x=atol(N);
		line.copy(N, line.size()-sep, sep+1);
		draw[0].y=atol(N);
		q.push(0);
		Second();
	}

	return 0;
}