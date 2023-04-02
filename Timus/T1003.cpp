#include<iostream>
using namespace std;

class HashMap{

	struct Node{
		int next, key,  prev;
		bool odd;
		Node(){
			next = -1;
			prev = -1;
			key = -1;
			odd = false;
		}
	};

	static const int SIZE = 999983;
	int first[ SIZE ];
	Node table[ 100000 ];
	int sz;
public:
	HashMap(){
		for (int i = 0; i < SIZE; ++i){
			first [ i ] = -1;
		}
		sz = 0;
	}

	int getIndex(int val){
		int key = val % SIZE;
		for (int i = first[key]; i != -1; i = table[i].next){
			if (table[i].key == val)
				return i;
		}
		return -1;
	}

	bool isExist(int val){
		return getIndex(val) != -1;
	}

	void addValue(int val, int prev, bool odd){
		int key = val % SIZE;
		table[ sz ].key = val;
		table[ sz ].prev = prev;
		table[ sz ].odd = odd;
		table[ sz ].next = first[key];

		first[ key ] = sz++;
	}

	int getPrev(int val){
		return table[ getIndex(val) ].prev;
	}

	bool getOdd(int val){
		return table[ getIndex(val) ].odd;
	}

	void clear(){
		sz = 0;
		for (int i = 0; i < SIZE; ++i)
			first[i] = -1;
	}
};

HashMap map;

bool add(int a, int b, bool odd){
	if (! map.isExist(b) ){
		map.addValue(b, a, odd);
	}
	int i = map.getPrev( b );
	if (i == a) return map.getOdd(b) == odd;
	if(i < a) return add (i, a-1, odd != map.getOdd(b));
	return add (a, i-1, odd != map.getOdd(b));
}

int main (){
#ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif

	for (;;){
		map.clear();

		int len, n;
		bool ans = false;

		scanf("%d\n", &len);
		if(len == -1) return 0;

		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i){

			int left, right;
			char s[20];

			scanf("%d %d %s\n", &left, &right, s);

			if(ans) continue;

			if(left > right) swap(left, right);
			if(! add(left, right, s[0]=='o')){
				ans = true;
				printf("%d\n", i);
			}
		}

		if(!ans) printf("%d\n", n);
	}
	
	return 0;
}