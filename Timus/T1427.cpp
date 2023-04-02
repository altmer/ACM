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

char str[100203];
char ch;
int n, m, cur, ans;
bool sm;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1427.in", "r", stdin);
	freopen ("T1427.out", "w", stdout);
#endif

	scanf ("%d%d", &n, &m);
	scanf ("%c", &ch);
	
	do{
		scanf ("%c", &ch);
		if (ch=='\n')
			break;
		cur++;
		if (!isalpha(ch) && !isspace(ch)){
			sm=true;
		}
		if (sm){
			if (cur>n){
				++ans;
				sm=!isalpha(ch) && !isspace(ch);
				cur=1;
			}
		}
		else{
			if (cur>m){
				++ans;
				cur=1;
			}
		}
	}while (ch!='\n');

	ans++;
	printf ("%d", ans);

	return 0;
}