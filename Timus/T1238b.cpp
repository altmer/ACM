#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int conc=1000;
vector <vector <int> > A, O;
int len;
string s;

void init (void)
{
	getline (cin, s);
	len=s.size();
	A.resize(len);
	O.resize(len);
	for (int i=0; i<len; ++i){
		A[i].resize(len);
		O[i].resize(len);
		A[i][i]=1;
		O[i][i]=-1;
	}
}

void rec (int i, int j)
{
	int op=O[i][j];
	if (op<0){
		for (int k=i; k<=j; ++k)
			printf ("%c", s[k]);
	}
	else if (op<conc){
		rec (i, op);
		rec (op+1, j);
	}
	else{
		op-=conc;
		printf ("%d(",(j-i+1)/op);
		rec(i, i+op-1);
		printf (")");
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1238.in", "r", stdin);
	freopen ("T1238.out", "w", stdout);
#endif

	init ();

	for (int l=2; l<=len; ++l){
		for (int i=0; i<=len-l; ++i){
			int min=l;
			int op=-1;
			int t;
			int j=i+l-1;
			// сложить
			for (int k=i; k<=j-1;++k){
				t=A[i][k]+A[k+1][j];
				if (t<min){
					min=t;
					op=k;
				}
			}
			// свернуть
			for (int f=1; f<=l/2; ++f){
				bool res=true;
				if (l%f)
					res=false;
				int cnt=1;
				while (res && i+f*cnt<=j){
					if (s.substr(i, f)==s.substr(i+f*cnt,f))
						++cnt;
					else
						res=false;
				}
				if (res)
				{
					t=3+A[i][i+f-1]+bool(cnt/10)+bool(cnt/100);
					if (t<min){
						min=t;
						op=conc+f;
					}
				}
			}
			A[i][j]=min;
			O[i][j]=op;
		}
	}

	rec (0, len-1);

	return 0;
}