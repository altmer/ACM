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
#include <limits>
#include <set>
using namespace std;

class deposit{
public:
	double s;
	int time;
	deposit (double a =0, int b = 0) : s(a), time(b) {}
};

vector <deposit> b1, b2, b3;
int t1, t2, t3, p1, p2, p3;
double s;
int month;
double sum;

int main (void)
{
	freopen ("income.in", "r", stdin);
	freopen ("income.out", "w", stdout);

	cin >> s >> t1 >> t2 >> t3 >> p1 >> p2 >> p3;
	b1.push_back(deposit(s, 0));
	b2.push_back(deposit(s, 0));
	b3.push_back(deposit(s, 0));

	int cur_t=0;

	while (cin >> month >> sum){
		if (month>cur_t){
			for (; cur_t<month; ++cur_t){
				for (int i=0; i<b1.size(); ++i){
					if (cur_t-b1[i].time!=0 && (cur_t-b1[i].time)%t1==0){
						b1[i].s*=1.0+double(p1)/100.0;
					}
				}
				for (int i=0; i<b2.size(); ++i){
					if (cur_t-b2[i].time!=0 && (cur_t-b2[i].time)%t2==0){
						b2[i].s*=1.0+double(p2)/100.0;
					}
				}
				for (int i=0; i<b3.size(); ++i){
					if (cur_t-b3[i].time!=0 && (cur_t-b3[i].time)%t3==0){
						b3[i].s*=1.0+double(p3)/100.0;
					}
				}
			}
		}

		if (sum>0){
			b1.push_back(deposit(sum, cur_t-1));
			b2.push_back(deposit(sum, cur_t-1));
			b3.push_back(deposit(sum, cur_t-1));
		}
		else{
			double t=fabs(sum);
			while (t>0){
				b1.back().s-=t;
				if (b1.back().s>0){
					t=0;
				}
				else{
					t=fabs(b1.back().s);
					b1.pop_back();
				}
			}
			t=fabs(sum);
			while (t>0){
				b2.back().s-=t;
				if (b2.back().s>0){
					t=0;
				}
				else{
					t=fabs(b2.back().s);
					b2.pop_back();
				}
			}
			t=fabs(sum);
			while (t>0){
				b3.back().s-=t;
				if (b3.back().s>0){
					t=0;
				}
				else{
					t=fabs(b3.back().s);
					b3.pop_back();
				}
			}
		}
	}

	for (; cur_t<=12; ++cur_t){
		for (int i=0; i<b1.size(); ++i){
			if (cur_t-b1[i].time!=0 && (cur_t-b1[i].time)%t1==0){
				b1[i].s*=1.0+double(p1)/100.0;
			}
		}
		for (int i=0; i<b2.size(); ++i){
			if (cur_t-b2[i].time!=0 && (cur_t-b2[i].time)%t2==0){
				b2[i].s*=1.0+double(p2)/100.0;
			}
		}
		for (int i=0; i<b3.size(); ++i){
			if (cur_t-b3[i].time!=0 && (cur_t-b3[i].time)%t3==0){
				b3[i].s*=1.0+double(p3)/100.0;
			}
		}
	}

	double ans=0;
	for (int i=0; i<b1.size(); ++i){
		ans+=b1[i].s;
	}
	cout << int(ans) << " ";

	ans=0;
	for (int i=0; i<b2.size(); ++i){
		ans+=b2[i].s;
	}
	cout << int(ans) << " ";

	ans=0;
	for (int i=0; i<b3.size(); ++i){
		ans+=b3[i].s;
	}
	cout << int(ans) << "\n";

	return 0;
}