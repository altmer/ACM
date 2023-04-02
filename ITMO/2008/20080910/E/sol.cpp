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

int x;
vector <int> primes;
string ans, tmp;

bool isprime(int& x){
	int lim = sqrt(double(x));
	for (int i=3; i<=lim; i+=2){
		if (x%i==0){
			return false;
		}
	}
	return true;
}

int main (void)
{
	freopen ("divisors.in", "r", stdin);
	freopen ("divisors.out", "w", stdout);

	primes.reserve(1000000);
	primes.push_back(2);
	for (int i=3; i<=500000; i+=2){
		if (isprime(i)){
			primes.push_back(i);
		}
	}
	scanf ("%d", &x);

	int lim=x/2;
	for (int i=0; i<primes.size() && primes[i]<=lim; ++i){
		if (x%primes[i]==0){
			char str[20];
			sprintf (str, "%d", primes[i]);
			tmp=str;
			if (ans.empty() || tmp<ans){
				ans=tmp;
			}
		}
	}

	if (ans.empty()){
		printf ("%d", x);
	}
	else{
		cout << ans;
	}

	return 0;
}