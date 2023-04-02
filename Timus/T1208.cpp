#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <sstream>
using namespace std;

string line, word;
vector <vector <string> > team;
bool A[20][20], C[20];
int E[20];
int n, ans=0;

void init(void)
{
	scanf ("%d\n", &n);
	team.resize (n);
	for (int i=0; i<n; ++i)
	{
		C[i]=true;
		getline (cin, line);
		istringstream iss (line);
		while (iss >> word)
			team[i].push_back(word);
		
		for (int j=0; j<i; ++j)
		{
			bool res=false;
			for (int k=0; k<team[j].size(); ++k)
			{
				if (res)
					break;

				for (int l=0; l<team[i].size(); ++l)
					if (team[j][k]==team[i][l])
					{
						res=true;
						A[j][i]=true;
						A[i][j]=true;
						++E[i];
						++E[j];
					}
			}
		}
	}
}

int fmax(void)
{
	int m=0, ans=-1;
	for (int i=0; i<n; ++i)
		if (E[i]>m)
		{
			ans=i;
			m=E[i];
		}
	return ans;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1208.in", "r", stdin);
	freopen ("T1208.out", "w", stdout);
#endif

	init ();
	int k;
	
	while ((k=fmax())!=-1)
	{
		C[k]=false;
		for (int i=0; i<n; ++i)
		{
			if (A[k][i])
			{
				A[k][i]=false;
				A[i][k]=false;
				E[i]--;
				E[k]--;
				if (!E[k])
					break;
			}
		}
	}
	
	for (int i=0; i<n; ++i)
		if (C[i])
			++ans;

	cout << ans;

	return 0;
}