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

	string codes[26] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18",
		"19", "20", "21", "22", "23", "24", "25", "26"};

class BreakingTheCode{
public:
	int find_code (string l){
		for (int i=0; i<26; ++i){
			if (codes[i]==l)
				return i;
		}
	}
	int find_char(char ch, string l){
		for (int i=0; i<l.size(); ++i){
			if (l[i]==ch)
				return i;
		}
	}
	string decodingEncoding(string s, string m){
		string ans;
		if (isdigit(m[0])){
			for (int i=0; i<m.size(); i+=2){
				string t=m.substr(i, 2);
				int k=find_code(t);
				ans+=s[k];
			}
		}
		else{
			for (int i=0; i<m.size(); ++i){
				int k=find_char(m[i], s);
				ans+=codes[k];
			}
		}
		return ans;
	}	
};

//declarations
string s1, s2;
BreakingTheCode solve;

void input (void){
	getline (cin, s1);
	getline (cin, s2);
}

void output (void){
	string a=solve.decodingEncoding(s1, s2);
	cout << a;
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}