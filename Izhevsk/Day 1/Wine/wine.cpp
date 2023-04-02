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
#include <complex>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

const double PI = 3.1415926535897932384626433832795;
typedef complex<double> base;

int nn=30100;
vector<int> a, b, res;
int n1, n2, n;

void fft(const vector<int>& a, vector<base>& res){
    int nnn = (int)a.size();
    if(nnn==1){
        res.assign(1, a[0]);
        return;
    }
    
    base w(1);
    base wn(cos(PI*2/(double)nnn), sin(PI*2/(double)nnn));

    vector<base> f0, f1;

    vector<int> a0(nnn/2);
    for (int i=0; i<nnn; i+=2){
        a0[i>>1]=a[i];
    }
    fft(a0, f0);

    vector<int> a1(nnn/2);
    for (int i=1; i<nnn; i+=2){
        a1[i>>1]=a[i];
    }
    fft(a1, f1);

    res.resize(nnn);
    for (int k=0; k<nnn/2; ++k){
        res[k] = f0[k] + w*f1[k];
        res[k+nnn/2] = f0[k] - w*f1[k];
        w*=wn;
    }
}

void fft_back(vector<base>& a){
    int nnn = (int)a.size();
    if(nnn==1) return;

    base w(1);
    base wn(cos(-PI*2/(double)nnn), sin(-PI*2/(double)nnn));

    vector<base> a0(nnn/2);
    for (int i=0; i<nnn; i+=2)
        a0[i>>1]=a[i];
    fft_back(a0);

    vector<base> a1(nnn/2);
    for (int i=1; i<nnn; i+=2)
        a1[i>>1]=a[i];
    fft_back(a1);

    for (int k=0; k<nnn/2; ++k){
        a[k] = a0[k] + w*a1[k];
        a[k+nnn/2] = a0[k] - w*a1[k];
        a[k]/=2;
        a[k+nnn/2]/=2;
        w*=wn;
    }
}

void multiply(){
    // get 2*n
    n=1;
    while(n<nn) n<<=1;
    n<<=1;

    a.resize(n);
    b.resize(n);

    vector<base> fa, fb;
    fft(a, fa);
    fft(b, fb);

    vector<base> res1(n);
    for (int i=0; i<n; ++i)
        res1[i]=fa[i]*fb[i];

    fft_back(res1);

	res.resize(n);
    for (int i=0; i<n; ++i){
        res[i]=(int)floor(res1[i].real()+0.5);
    }
}

int main (void){
    freopen ("wine.in", "r", stdin);
    freopen ("wine.out", "w", stdout);

	scanf("%d", &n1);
    a.resize(nn);
    for (int i=0; i<n1; ++i){
		int tmp;
        scanf("%d", &tmp);
		a[tmp]=1;
    }

    scanf("%d", &n2);
    b.resize(nn);
    for (int i=0; i<n2; ++i){
		int tmp;
        scanf("%d", &tmp);
		b[tmp]=1;
    }

    multiply();

    for (int i=0; i<n; ++i){
        if(res[i]){
            printf("%d %d\n", i, res[i]);
        }
    }

    return 0;
}