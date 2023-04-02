#include <iostream>
#include <sstream>
#include <cstdio>
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
#include <map>
#include <set>
using namespace std;

int ntest;
vector <string> n_name (1010), s_name (1010);
vector <int> n_cost(1010), s_cost(1010);
vector <vector <long long> > sum, num;
int n_num, s_num;

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	cin >> ntest;

	for (int test=0; test<ntest; ++test){
		long long maxx=0;
		int c_ans=0;

		cin >> n_num;
		string tmp;
		for (int i=0; i<n_num; ++i){
			cin >> tmp >> n_name[i] >> n_cost[i];
		}
		cin >> s_num;
		for (int i=0; i<s_num; ++i){
			cin >> tmp >> s_name[i] >> s_cost[i];
		}

		sum.assign(s_num, vector <long long> (n_num, 0));
		num.assign(s_num, vector <long long> (n_num, 0));

		for (int i=0; i<s_num; ++i){
			for (int j=0; j<n_num; ++j){
				// without bridge
				if (i>0){
					if (sum[i-1][j]>sum[i][j] || (sum[i-1][j]==sum[i][j] && num[i-1][j]<num[i][j])){
						sum[i][j]=sum[i-1][j];
						num[i][j]=num[i-1][j];
					}
				}
				if (j>0){
					if (sum[i][j-1]>sum[i][j] || (sum[i][j-1]==sum[i][j] && num[i][j-1]<num[i][j])){
						sum[i][j]=sum[i][j-1];
						num[i][j]=num[i][j-1];
					}
				}
				// with bridge
				if (s_name[i]==n_name[j]){
					if (i>0 && j>0){
						long long ss=sum[i-1][j-1]+s_cost[i]+n_cost[j];
						int nn=num[i-1][j-1]+1;
						if (ss>sum[i][j] || (ss==sum[i][j] && nn<num[i][j])){
							sum[i][j]=ss;
							num[i][j]=nn;
						}
					}
					else{
						long long ss=s_cost[i]+n_cost[j];
						int nn=1;
						if (ss>sum[i][j] || (ss==sum[i][j] && nn<num[i][j])){
							sum[i][j]=ss;
							num[i][j]=nn;
						}
					}
				}
			}
		}

		for (int j=0; j<n_num; ++j){
			if (sum[s_num-1][j]>maxx || (sum[s_num-1][j]==maxx && num[s_num-1][j]<c_ans)){
				maxx=sum[s_num-1][j];
				c_ans=num[s_num-1][j];
			}
		}

		cout << maxx << " " << c_ans << "\n";
		//if (test!=ntest-1)
		//	cout << "\n";
	}

	return 0;
}