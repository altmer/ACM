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

int num, denum, k;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1468.in", "r", stdin);
	freopen ("T1468.out", "w", stdout);
#endif
	while(true){
		scanf ("%d%d%d", &num, &denum, &k);
		vector <int> mods(10000);
		if (!num)
			break;
		
		// целая часть

		vector <int> v;
		int n=num/denum;

		while (n){
			v.push_back(n%k);
			n/=k;
		}

		bool period=false;
		vector <int> w, m;
		
		// дробная часть

		n=num%denum;
		while (n){
			n*=k;
			w.push_back(n/denum);
			n%=denum;
			m.push_back(n);
			if (!mods[n]){
				mods[n]=w.size();
			}
			else{
				period=true;
				break;
			}
		}

		for (int i=v.size()-1; i>=0; --i){
			if (v[i]>9){
				printf("%c", 'A'+v[i]-10);
			}
			else{
				printf ("%d", v[i]);
			}
		}
		if (!w.empty()){
			if (v.empty())
				printf ("0");
			printf (".");
			if (!period){
				for (int i=0; i<w.size(); ++i){
					if (w[i]>9){
						printf("%c", 'A'+w[i]-10);
					}
					else{
						printf ("%d", w[i]);
					}
				}
			}
			else{
				int i=0;
				while (m[i]!=m.back()){
					if (w[i]>9){
						printf("%c", 'A'+w[i]-10);
					}
					else{
						printf ("%d", w[i]);
					}
					++i;
				}
				int end=w.size();
				if (w[i]!=w.back()){
					if (w[i]>9){
						printf("%c", 'A'+w[i]-10);
					}
					else{
						printf ("%d", w[i]);
					}
					++i;
				}
				else
					--end;
				printf("(");
				for (; i<end; ++i){
					if (w[i]>9){
						printf("%c", 'A'+w[i]-10);
					}
					else{
						printf ("%d", w[i]);
					}
				}
				printf (")");
			}
		}
		printf ("\n");
	}

	return 0;
}