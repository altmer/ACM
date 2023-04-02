#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

int n,x;
vector <int> v;
int forw=0, back=0;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	cin >> n >> x;
	v.resize(n);

	for (int i=0; i<n; ++i){
		cin >> v[i];
	}
	v.push_back(0);

	sort(v.begin(),v.end());

	//forward
	int uk=-1;
	for (int i=0; i<v.size(); ++i){
		if (v[i]>0){
			uk=i;
			break;
		}
	}
	if (x>0){
		if (uk!=-1){
			if (x<v[uk]){
				forw=abs(x);
				back+=abs(x);
			}
			else{
				cout << "Impossible\n";
				return 0;
			}
		}
		else{
			forw=abs(x);
			back+=abs(x);
		}
	}	
	else{
		if (uk!=-1)
			forw+=2*abs(v[uk]);
		else{
			cout << "Impossible\n";
			return 0;
		}
	}
	uk=-1;
	for (int i=v.size()-1; i>=0; --i){
		if (v[i]<0){
			uk=i;
			break;
		}
	}

	if (x<0){
		if (uk!=-1){
			if (x>v[uk]){
				forw+=abs(x);
				back+=abs(x);
			}
			else{
				cout << "Impossible\n";
				return 0;
			}
		}
		else{
			back+=abs(x);
			forw+=abs(x);
		}
	}
	else{
		if (uk!=-1)
			back+=2*abs(v[uk]);
		else{
			cout << "Impossible\n";
			return 0;
		}
	}

	cout << forw << ' ' << back << '\n';

	return 0;
}