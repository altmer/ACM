#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("dragon.in","r",stdin);
	freopen("dragon.out","w",stdout);
	int n;
	string s;
	cin >> n >> s;
	if(s.length()>n){
		cout << "No solution" << "\n";
		return 0;
	}else while(s.length()!=n)s.push_back('0');
	cout << s << "\n"; 
	return 0;
}