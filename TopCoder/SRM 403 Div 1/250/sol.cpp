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

int count_dig (int x){
	int res=0;
	while (x){
		++res;
		x/=10;
	}
	return res;
}

int pre_count_lucky (int num){
	int res=0;
	for (int i=1; i<num; ++i)
		res+=int(pow(2.0, double(i)));
	return res;
}

bool is_lucky (int x){
	while (x){
		if (x%10!=4 && x%10!=7)
			return false;
		x/=10;
	}
	return true;
}

int count_lucky (int x, int num){
	if (num==0)
		return 1;
	int d=x/int(pow(10.0, double(num-1)));
	if (d<4)
		return 0;
	if (d==4)
		return count_lucky(x%int(pow(10.0, double(num-1))), num-1);
	if (d<7)
		return int(pow(2.0, double(num-1)));
	if (d==7)
		return int(pow(2.0, double(num-1)))+count_lucky(x%int(pow(10.0, double(num-1))), num-1);
	return int(pow(2.0, double(num)));
}

class TheLuckyNumbers{
public:
	int count(int a, int b){
		int a_dig, b_dig, a_num, b_num;
		a_dig=count_dig(a);
		b_dig=count_dig(b);
		a_num=pre_count_lucky(a_dig)+count_lucky(a, a_dig);
		b_num=pre_count_lucky(b_dig)+count_lucky(b, b_dig);
		int t=is_lucky(a);
		return b_num-a_num+t;
	}
};

//declarations
int x, y;
TheLuckyNumbers solve;

void input (void){
	scanf ("%d%d", &x, &y);
}

void output (void){
	printf ("%d", solve.count(x, y));
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}