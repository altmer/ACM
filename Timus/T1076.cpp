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

vector <vector <int> > A, C, M;
vector <int> row, col;
vector <pair <int, int> > path;
int n, step=1;
int z0_r, z0_c;
bool done;

int step1(void){
	int minval;
	for (int i=0; i<n; ++i){
		minval=C[i][0];
		for (int j=1; j<n; ++j){
			if (C[i][j]<minval){
				minval=C[i][j];
			}
		}
		for (int j=0; j<n; ++j)
			C[i][j]-=minval;
	}
	return 2;
}

int step2 (void){
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (C[i][j]==0 && col[j]==0 && row[i]==0){
				M[i][j]=1;
				col[j]=1;
				row[i]=1;
			}
		}
	}
	col.assign(n, 0);
	row.assign(n, 0);
	return 3;
}

int step3 (void){
	int cnt=0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (M[i][j]==1){
				col[j]=1;
				cnt+=1;
			}
		}
	}
	if (cnt==n){
		done=true;
		return 0;
	}
	else{
		return 4;
	}
}

void find_zero (int &r, int &c){
	r=c=-1;
	int i=0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (C[i][j]==0 && row[i]==0 && col[j]==0){
				r=i;
				c=j;
				return;
			}
		}
	}
}

bool star_row (int r, int &c){
	c=-1;
	for (int i=0; i<n; ++i){
		if (M[r][i]==1){
			c=i;
			return true;
		}
	}
	return false;
}

int step4 (void){
	int r,c;
	while (true){
		find_zero(r,c);
		if (r<0){
			return 6;
		}
		M[r][c]=2;
		int c2=c;
		if (star_row(r, c2)){
			row[r]=1;
			col[c2]=0;
		}
		else{
			z0_r=r;
			z0_c=c;
			return 5;
		}
	}
}

int find_star_col (int c){
	for (int i=0; i<n; ++i){
		if (M[i][c]==1){
			return i;
		}
	}
	return -1;
}

int find_prime_row (int r){
	for (int i=0; i<n; ++i){
		if (M[r][i]==2){
			return i;
		}
	}
	return -1;
}

void convert_path (){
	for (int i=0; i<path.size(); ++i){
		if (M[path[i].first][path[i].second]==1){
			M[path[i].first][path[i].second]=0;
		}
		else if (M[path[i].first][path[i].second]==2){
			M[path[i].first][path[i].second]=1;
		}
	}
}

void clear_covers (void){
	row.assign(n, 0);
	col.assign(n, 0);
}

void erase_primes (void){
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (M[i][j]==2){
				M[i][j]=0;
			}
		}
	}
}

int step5(void){
	int cnt=0, r, c;
	bool res=false;
	path.clear();
	path.push_back(make_pair(z0_r, z0_c));
	while (!res){
		r=find_star_col (path[cnt].second);
		if (r!=-1){
			++cnt;
			path.push_back(make_pair(r, path[cnt-1].second));
		}
		else{
			res=true;
		}
		if (!res){
			c=find_prime_row(path[cnt].first);
			cnt++;
			path.push_back(make_pair(path[cnt-1].first, c));
		}
	}
	convert_path();
	clear_covers();
	erase_primes();
	return 3;
}

int find_small (void){
	int k=1e+9;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (row[i]==0 && col[j]==0 && k>C[i][j])
				k=C[i][j];
		}
	}
	return k;
}

int step6(){
	int q=find_small();
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (row[i]==1)
				C[i][j]+=q;
			if (col[j]==0)
				C[i][j]-=q;
		}
	}
	return 4;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1076.in", "r", stdin);
	freopen ("T1076.out", "w", stdout);
#endif

	scanf ("%d", &n);
	A.resize(n);
	C.resize(n);
	M.resize(n);
	row.resize(n);
	col.resize(n);

	for (int i=0; i<n; ++i){
		A[i].resize(n);
		C[i].resize(n);
		M[i].resize(n);
		for (int j=0; j<n; ++j){
			scanf ("%d", &A[i][j]);
			C[i][j]=1e+3-A[i][j];
		}
	}
	//C=A;

	while (!done){
		switch (step){
			case 1: step=step1();
				break;
			case 2: step=step2();
				break;
			case 3: step=step3();
				break;
			case 4: step=step4();
				break;
			case 5: step=step5();
				break;
			case 6: step=step6();
				break;
		}
	}

	int ans=0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (M[i][j]!=1){
				ans+=A[i][j];
			}
		}
	}
	printf ("%d", ans);

	return 0;
}