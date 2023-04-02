#include <iostream>
using namespace std;

const int MOD = 999983;

struct node{
	int next, key;
	int number;
};

int n;
int first[MOD];
node arr[500000];
int len = 0;
int cnt_type = 0;
int cnt_same = 0;
char s[100];

int find(int key){
	int ind = (key + 1000000001) % MOD;

	for (ind = first[ind]; ind != -1; ind = arr[ind].next){
		if (arr[ind].key == key)
			return ind;
	}
	return -1;
}

int push(int key){
	int ind = (key + 1000000001) % MOD;

	arr[len].next = first[ind];
	arr[len].key = key;
	arr[len].number = 0;

	first[ind] = len;

	return len++;
}

int main(){
	freopen("homo.in","r",stdin);
	freopen("homo.out","w",stdout);

	scanf("%d\n", &n);

	for (int i = 0; i < MOD; ++i)
		first[i] = -1;

	for (int i = 0; i < n; ++i){
		int cur;
		scanf("%s %d\n", s, &cur);

		if(s[0] == 'i'){
			int wh = find(cur);
			if(wh == -1) wh = push(cur);
			arr[wh].number++;

			if(arr[wh].number == 2)
				cnt_same++;
			if(arr[wh].number == 1)
				cnt_type++;
		}else if (s[0] == 'd'){
			int wh = find(cur);
			if(wh != -1 && arr[wh].number > 0) {
				arr[wh].number--;

				if(arr[wh].number == 1)
					cnt_same--;
				if(arr[wh].number == 0)
					cnt_type--;
			}
		}

		if(cnt_same && cnt_type > 1){
			puts("both");
		}else if (cnt_same){
			puts("homo");
		}else if (cnt_type > 1){
			puts("hetero");
		}else{
			puts("neither");
		}			
	}


	return 0;
}