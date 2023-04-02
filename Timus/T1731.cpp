#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i)
		cout << i + 1 << " " ;
	cout << endl;
	for (int i = 0; i < m; ++i)
		cout << (i + 1) * n + 1 << " " ;
	cout << endl;
	
	return 0;
}