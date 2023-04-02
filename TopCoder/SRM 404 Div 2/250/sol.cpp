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

class ReadingBooks{
public:
	int countBooks(vector <string> v){
		int i, s, e;
		for (int j=0; j<v.size(); ++j){
			if (v[j]=="introduction")
				++i;
			else if (v[j]=="story")
				++s;
			else if (v[j]=="edification")
				++e;
		}
		return min(i, min(s,e));
	}	
};

//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}