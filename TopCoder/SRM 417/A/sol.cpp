#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class TemplateMatching{
public:
	string bestMatch(string text, string prefix, string suffix)
	{
		int c_pref=0;
		int c_suf=0;
		int c_ans=0;
		string ans="";
		vector <vector <int> > A;
		A.assign(text.size(), vector <int> (text.size(), 0));
		for (int len=1; len<=text.size(); ++len){
			for (int i=0; i<=text.size()-len; ++i){
				int j = i + len - 1;
				if (j>0 && A[i][j-1]!=0){
					A[i][j]=A[i][j-1];
				}
				if (len<=prefix.size()){
					string sub = text.substr(i, len);
					if (sub==prefix.substr(prefix.size()-len, len)){
						A[i][j]=max(A[i][j], len);
					}
				}
			}
		}

		vector <vector <int> > B;
		B.assign(text.size(), vector <int> (text.size(), 0));
		for (int len=1; len<=text.size(); ++len){
			for (int j=text.size()-1; j>=len-1; --j){
				int i = j - len + 1;
				if (i+1<text.size() && B[i+1][j]!=0){
					B[i][j]=B[i+1][j];
				}
				if (len<=suffix.size()){
					string sub = text.substr(i, len);
					if (sub==suffix.substr(0, len)){
						B[i][j]=max(B[i][j], len);
					}
				}
			}
		}

		for (int i=0; i<text.size(); i++){
			for (int j=i; j<text.size(); j++){
				if (A[i][j]+B[i][j]>c_ans){
					c_ans=A[i][j]+B[i][j];
					c_pref=A[i][j];
					c_suf=B[i][j];
					ans=text.substr(i, j-i+1);
				}
				else if (A[i][j]+B[i][j]==c_ans){
					if (A[i][j]==c_pref){
						if (ans.empty()){
							ans=text.substr(i, j-i+1);
							c_pref=A[i][j];
							c_suf=B[i][j];
						}
						else{
							if (ans>text.substr(i, j-i+1)){
								ans=text.substr(i, j-i+1);
								c_pref=A[i][j];
								c_suf=B[i][j];
							}
						}
					}
					else{
						if (A[i][j]>c_pref){
							ans=text.substr(i, j-i+1);
							c_pref=A[i][j];
							c_suf=B[i][j];
						}
					}
				}
			}
		}
		// end of method
		return ans;
	}
};

//declarations
TemplateMatching solve;

void input (void){
}

void output (void){
	cout << solve.bestMatch("ab", "a","a");
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}