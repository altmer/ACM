#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<limits>
#include<cmath>
using namespace std;
const double eps = 1e-8;

class point{
public:
	double x, y;
	double len()const{
		return x*x+y*y;
	}
	double dist(const point& T)const{
		return (x-T.x)*(x-T.x)+(y-T.y)*(y-T.y);
	}
};

class hash{
public:
	double a, b, c;
	bool operator ==(const hash& T) const{
		return fabs(a-T.a)<eps && fabs(b-T.b)<eps && fabs(c-T.c)<eps;
	}
};

int n;
point arr1[100100], arr2[100100];
hash mas1[100100],mas2[200200];
int F[100100];
double sumx1=0, sumx2=0, sumy1=0, sumy2=0;
point c1, c2;

hash vp(const point& v1, const point& v2, const point& c){
	hash ret;
	ret.a = v1.dist(c);
	ret.b = v2.dist(c);
	ret.c = v1.dist(v2);
	return ret;
}

void prefix(){
	F[0]=F[1]=0;
	for (int i=2; i<=n; ++i){
		int j=F[i-1];
		for(;;){
			if(mas1[j]==mas1[i-1]){
				F[i]=j+1;
				break;
			}else if(j>0){
				j=F[j];
			}else{
				F[i]=0;
				break;
			}
		}
	}
}

bool kmp(){
	prefix();
	int i=0,j=0;
	for(;;){
		if(j==2*n) return false;
		if(mas1[i]==mas2[j]){
			i++;
			j++;
			if(i==n) return true;
		}else if(i>0){
			i=F[i];
		}else{
			j++;
		}
	}
}

int main(void){
	// COMMENT THIS!!!!!!!!!!!!!!!!!!!!

	/*
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	*/


	scanf("%d", &n);
	int a, b;
	for (int i=0; i<n; ++i){
		scanf("%d%d", &a,&b);
		arr1[i].x=a;
		arr1[i].y=b;
		sumx1+=double(arr1[i].x);
		sumy1+=double(arr1[i].y);
	}
	c1.x = sumx1/double(n);
	c1.y = sumy1/double(n);
	for (int i=0; i<n; ++i){
		scanf("%d%d", &a,&b);
		arr2[i].x=a;
		arr2[i].y=b;
		sumx2+=double(arr2[i].x);
		sumy2+=double(arr2[i].y);
	}
	c2.x = sumx2/double(n);
	c2.y = sumy2/double(n);

	for (int i=0; i<n; ++i){
		mas1[i]=(vp(arr1[i],arr1[(i+1)%n], c1));
		mas2[i]=(vp(arr2[i],arr2[(i+1)%n], c2));
	}
	for (int i=0; i<n; ++i){
		mas2[i+n]=mas2[i];
	}

	if(kmp()) cout << "YES\n"; 
	else cout << "NO\n";
	
	return 0;
}