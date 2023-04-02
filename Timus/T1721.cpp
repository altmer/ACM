#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int dest, next;
};

const int TEST = 1;
const int STAT = 2;
int n;
char names[1024][30];
int can[1024];
int rat[1024];
char s[100];

int l[1024];
int numl = 0;
int r[1024];
int numr = 0;

int first[1024];
node arr[10000000];
int num = 0;
int mt[1024];

bool used[1024];

bool kuhn(int u){
	if(used[u]) return false;
	used[u] = true;

	for (int ind = first[u]; ind != -1; ind = arr[ind].next){
		int v = arr[ind].dest;
		
		if (mt[v] == -1 || kuhn(mt[v])){
			mt[v] = u;
			return true;
		}
				
	}

	return false;
}

int main(void){

	scanf ("%d\n", &n);

	for (int i = 0; i < n; ++i)
		first[i] = -1;

	for (int i = 0; i < n; ++i){
		scanf("%s %s %d\n", names[i], s, &rat[i]);
		switch(s[0]){
			case 'a':
				can[i] = TEST + STAT;
				break;
			case 's':
				can[i] = STAT;
				break;
			case 't':
				can[i] = TEST;
				break;
		}

		if (rat[i] % 4 < 2)
			l[numl++] = i;
		else
			r[numr++] = i;
	}

	for (int i = 0; i < numl; ++i){
		for (int j = 0; j < numr; ++j){
			if ( abs ( rat[ l[i] ] - rat[ r[j] ] ) == 2 && ((can [ l[i] ] | can[ r[j] ]) == TEST + STAT )){

				arr[num].next = first[i];
				arr[num].dest = j;
				first[i] = num++;

			}
		}
	}

	for (int i = 0; i < numr; ++i)
		mt[i] = -1;

	for (int i = 0; i < numl; ++i){

		for (int j = 0; j < numl; ++j)
			used[j] = false;

		kuhn(i);
	}

	int cnt = 0;
	for (int i = 0; i < numr; ++i)
		cnt += mt[i] != -1;

	printf("%d\n", cnt);

	for (int i = 0; i < numr; ++i){
		if (mt[i] != -1){
			int q = i;
			int w = mt[i];

			if ( (can[ r[q] ] & STAT ) > 0 && (can[ l[w] ] & TEST ) > 0){
				printf("%s %s\n", names[r[q]], names[l[w]]);
			}else if ((can[ l[w] ] & STAT ) > 0 && (can[ r[q] ] & TEST ) > 0 ){
				printf("%s %s\n", names[l[w]], names[r[q]]);
			}
		}
	}

	return 0;
}