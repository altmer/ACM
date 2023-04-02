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
long long n, num;

int main (void)
{
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	cin >> ntest;

	for (int test=0; test<ntest; ++test){
		cin >> num;
		n=num/5;
		if (num-n*5){
			++n;
		}
		long long alen(-1), awid(-1), adif(-1), ans(1000000000);
		ans*=ans;
		long long len(alen), wid(awid);
		double lim = sqrt (double(n));
		for (long long s=1; s<=lim; ++s){
			long long t=n/s;
			if (n-t*s){
				++t;
			}
			wid=4+s*8+(s-1)*2;
			len=t*40+(t-1)*4+8;
			long long tmp1=len*wid;
			long long tmp2=len-wid;
			if (tmp1<ans){
				ans=tmp1;
				alen=len;
				awid=wid;
				adif=tmp2;
			}
			else if (tmp1==ans && tmp2<adif){
				alen=len;
				awid=wid;
				adif=tmp2;
			}
			wid=4+t*8+(t-1)*2;
			len=s*40+(s-1)*4+8;
			tmp1=len*wid;
			tmp2=len-wid;
			if (tmp1<ans){
				ans=tmp1;
				alen=len;
				awid=wid;
				adif=tmp2;
			}
			else if (tmp1==ans && tmp2<adif){
				alen=len;
				awid=wid;
				adif=tmp2;
			}
		}
		cout <<max(alen,awid) << " X " << min(awid,alen) << " = " <<  ans << "\n";
	}

	return 0;
}