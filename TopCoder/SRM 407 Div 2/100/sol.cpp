#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class CheapestRoute{
public:
	vector <int> routePrice(vector <int> cp, vector <int> ec, vector <int> exc, int tp){
		vector <int> cost (cp.size(), 0), move(cp.size(), 0), tel(cp.size(), 0);
		queue <int> q;
		if (cp.back()==-1){
			cost.clear();
			return cost;
		}
		q.push(0);
		cost[0]=1;
		while (!q.empty()){
			int u=q.front();
			q.pop();
			// teleport
			for (int i=0; i<ec.size(); ++i){
				if (ec[i]==u){
					int v=exc[i];
					if (cp[v]!=-1 && (cost[v]==0 || cost[v]>cost[u]+tp+tel[u] || (cost[v]==cost[u]+tp+tel[u] && move[v]>move[u]+1))){
						cost[v]=cost[u]+tp+tel[u];
						move[v]=move[u]+1;
						tel[v]=tel[u]+1;
						q.push(v);
					}
				}
			}
			// left
			if (u-1>=0){
				int v=u-1;
				if (cp[v]!=-1 &&(cost[v]==0 || cost[v]>cost[u]+cp[v]|| (cost[v]==cost[u]+cp[v] && move[v]>move[u]+1))){
					cost[v]=cost[u]+cp[v];
					move[v]=move[u]+1;
					tel[v]=tel[u];
					q.push(v);
				}
			}
			// right
			if (u+1<cp.size()){
				int v=u+1;
				if (cp[v]!=-1 &&(cost[v]==0 || cost[v]>cost[u]+cp[v]|| (cost[v]==cost[u]+cp[v] && move[v]>move[u]+1))){
					cost[v]=cost[u]+cp[v];
					move[v]=move[u]+1;
					tel[v]=tel[u];
					q.push(v);
				}
			}
		}
		cost.back()--;
		if (cost.back()==-1){
			cost.clear();
			return cost;
		}
		vector <int> ans;
		ans.push_back(cost.back());
		ans.push_back(move.back());
		return ans;
	}
};

//declarations
CheapestRoute solve;

void input (void){
	
}

void output (void){
	vector <int> v1, v2, v3, v4;
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(1000);
	v1.push_back(1000);
	v1.push_back(1000);
	v2.push_back(0);
	v2.push_back(3);
	v3.push_back(4);
	v3.push_back(6);
	v4=solve.routePrice(v1, v2, v3, 0);
	cout << v4[0] << " " << v4[1];
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}