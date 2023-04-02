#include<iostream>
using namespace std;

int d[32][32];
int res[32][32];
int tmp[32][32];
int m;
int p;
char s[200];
const int LEN = 200;
int num[LEN + 1];

bool isOdd(){
	return num[ LEN ] & 1;
}

void divideByTwo(){
	int carry = 0;
	for (int i = LEN - num[ 0 ] + 1; i <= LEN; ++i){
		num[ i ] = carry * 10 + num[ i ];
		carry = num [ i ] % 2;
		num[ i ] /= 2;
	}
	while(num[ 0 ] && num[ LEN - num[ 0 ] + 1 ] == 0){
		num[ 0 ]--;
	}
}

void decrement(){
	num[ LEN ]--;
	if (num[ LEN ] == 0 && num[ 0 ] == 1)
		num[ 0 ] = 0;
}

void increment(){
	num[ LEN ]++;
	int i = LEN - 1;
	int carry = num[ LEN ] / 10;
	num[ LEN ] %= 10;
	while(carry){
		num[ i ] += carry;
		carry = num[ i ] / 10;
		num[i]%=10;
		i--;
	}
	if(i < LEN - num[ 0 ] + 1){
		num[ 0 ]++;
	}
}

void power(){
	int n = 1<<m;
	for (int i = 0; i < n; ++i){
		res[ i ][ i ] = 1;
	}

	while(num[ 0 ]){
		if(! isOdd() ){
			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n ; ++j){
					tmp[ i ][ j ] = 0;
				}
			}

			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n; ++j){
					for (int k = 0; k < n; ++k){
						tmp[ i ][ k ] += (d[ i ][ j ] * d[ j ][ k ]);
						tmp[ i ][ k ] %= p;
					}					
				}
			}

			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n ; ++j){
					d[ i ][ j ] = tmp[ i ][ j ] % p;
				}
			}
			divideByTwo();
		}else{
			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n ; ++j){
					tmp[ i ][ j ] = 0;
				}
			}

			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n; ++j){
					for (int k = 0; k < n; ++k){
						tmp[ i ][ k ] += (res[ i ][ j ] * d[ j ][ k ]);
						tmp[ i ][ k ] %= p;
					}					
				}
			}

			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n ; ++j){
					res[ i ][ j ] = tmp[ i ][ j ];
				}
			}
			decrement();
		}
	}
}

bool getbit(int x, int n){
	return x&(1<<n);
}
bool norm(int a, int b){
	int h=m;
	for(int i=0;i<h-1;i++){
		int smp=getbit(a,i);
		if(smp == getbit(a,i+1) && smp == getbit(b,i) && smp == getbit(b,i+1))
			return false;
	}
	return true;
}

void filld(){
	for(int i=0;i<(1<<m);i++)
		for(int j=0;j<(1<<m);j++){
			if(norm(i,j))d[i][j]=1;
		}
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%s %d %d", s, &m, &p);
	filld();
	num[ 0 ] = strlen(s);
	for (int i = 0; i < num[ 0 ]; ++i){
		num[LEN - num[ 0 ] + 1 + i] = s[ i ] - '0';
	}
	increment();
	power();
	
	int n = 1 << m;
	if(n >= 21) printf("%d", res[21][21]);
	else if (n >= 5) printf("%d", res[5][5]);
	else printf("%d", res[1][1]);

	return 0;
}