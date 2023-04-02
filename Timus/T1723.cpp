#include<iostream>
#include<algorithm>
using namespace std;

char s [100];
int num[300];
char best;
int curmax = 0;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	gets(s);

	int len = strlen(s);
	for (int i =0; i < len; ++i){
		num[s[i]]++;
		if(num[s[i]] > curmax){
			curmax = num[s[i]];
			best = s[i];
		}
	}

	printf("%c\n", best);
	
	return 0;
}