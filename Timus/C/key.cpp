#include<iostream>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

struct st{
	ull code;
	int start, stringNumber;

	bool operator <(const st& T) const{
		return code < T.code || code == T.code && stringNumber < T.stringNumber;
	}
};

ull p[105];
int n;
char text[1020][105];
int slen[1020];
ull hash[1020][105];
int maxlen = 0;
int m = 101;
st vec[200000];
int len = 0;
int anslen[1020];
int ansstart[1020];

int main(void){

	p[0] = 1;
	for (int i = 1; i < 102; ++i){
		p[i] = p[i-1] * 31;
	}
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i){
		anslen[i] = -1;
		gets(text[i]);

		slen[i] = strlen(text[i]);

		maxlen = max(slen[i], maxlen);
		for (int j = 0; j < slen[i]; ++j){
			hash[i][j] = (text[i][j] - 'a' + 1) * p[j];
			if(j) hash[i][j] += hash[i][j-1];
		}
	}

	for (int curlen = 1; curlen <= maxlen; ++curlen){
		len = 0;

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < slen[i] - curlen + 1; ++j){
				ull curhash = hash[i][j + curlen - 1];
				if (j>0) curhash -= hash[i][j - 1];
				curhash *= p[m - j];

				vec[len].code = curhash;
				vec[len].start = j;
				vec[len].stringNumber = i;

				len++;
			}
		}

		sort(vec, vec + len);

		int cur = 0;
		bool same = true;
		for (int i = 1; i < len; ++i){
			if (vec[i].code == vec[cur].code){
				same = vec[i].stringNumber == vec[cur].stringNumber;
			}else{
				if (same && anslen[vec[cur].stringNumber] == -1){
					anslen[vec[cur].stringNumber] = curlen;
					ansstart[vec[cur].stringNumber] = vec[cur].start;
				}
				cur = i;
				same = true;
			}
		}

		if (same && anslen[vec[cur].stringNumber] == -1){
			anslen[vec[cur].stringNumber] = curlen;
			ansstart[vec[cur].stringNumber] = vec[cur].start;
		}

	}

	for (int i = 0; i < n; ++i){
		for (int j = ansstart[i]; j < ansstart[i] + anslen[i]; ++j){
			printf("%c", text[i][j]);
		}
		puts("");
	}

	return 0;
}