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

int a, b, n, x, y, c, ans;
int ax, ay;

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1430.in", "r", stdin);
	freopen ("T1430.out", "w", stdout);
#endif

	cin >> a >> b >> n;

	int rem3, rba=b%a;
	int rem4, rab=a%b;
	x=n/a;
	y=n/b;

	if (x<=1e+5){
		for (int i=0; i<=x; ++i){
			c=i*a;
			y=(n-c)/b;
			c+=b*y;
			if (c>ans){
				ans=c;
				ax=i;
				ay=y;
			}
		}
	}

	else if (y<=1e+5){
		for (int i=0; i<=y; ++i){
			c=i*b;
			x=(n-c)/a;
			c+=a*x;
			if (c>ans){
				ans=c;
				ax=x;
				ay=i;
			}
		}
	}
	else{
		for (int m=n; m>min(0, n-min(a,b)); --m){
			int rem1=m%a;
			int rem2=m%b;
			rem3=rem1%b;
			rem4=rem2%a;
			x=m/a;
			y=m/b;
			if (rem1==0){
				ax=x;
				ay=0;
				break;
			}
			if (rem2==0){
				ax=0;
				ay=y;
				break;
			}
			if (rem3==0){
				ax=x;
				ay=rem1/b;
				break;
			}
			if (rem4==0){
				ax=rem2/a;
				ay=y;
				break;
			}
			bool fin=false;
			int k=rem3;
			int l=k;
			k=(k+rab)%b;
			while (x>0 && k!=l){
				x--;
				if (k==0){
					fin=true;
					break;
				}
				k=(k+rab)%b;
			}
			if (fin && x>0){
				ax=x;
				ay=(n-x*a)/b;
				break;
			}
			fin=false;
			k=rem4;
			l=k;
			k=(k+rba)%a;
			while (k!=l && y>0){
				y--;
				if (k==0){
					fin=true;
					break;
				}
				k=(k+rba)%a;
			}
			if (fin && y>0){
				ax=(n-y*b)/a;
				ay=y;
				break;
			}

		}
	}

	cout << ax << " " << ay;

	return 0;
}