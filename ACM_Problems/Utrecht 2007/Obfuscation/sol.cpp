#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

class word{
public:
	int let[30];
	string text;
	word (const string& t="") : text(t)
	{
		for (int i=0; i<30; ++i)
			let[i]=0;
		for (int i=1; i<text.size()-1; ++i){
			++let[text[i]-'a'];
		}
	}
	const char& flet()
	{
		if (!text.empty())
			return text[0];
		else
			return ' ';
	}
	const char& llet()
	{
		if (!text.empty())
			return text[text.size()-1];
		else
			return ' ';
	}
};

int ntest;
vector <vector <word> > A(30);
string patt, tmp;
vector <int> num;
vector <string> w;
vector <vector <int> > B;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	cin >> ntest;
	for (int test=0; test<ntest; ++test){
		int n;
		cin >> patt >> n;

		num.assign(patt.size()+1, 0);
		w.assign(patt.size()+1, "");
		B.assign(patt.size()+1, vector <int> (30, 0));

		for (int i=0; i<n; ++i){
			cin >> tmp;
			A[tmp[0]-'a'].push_back(word(tmp));
		}

		B[0][patt[0]-'a']=1;
		for (int i=1; i<patt.size(); ++i){
			B[i][patt[i]-'a']=1;
			for (char c='a'; c<='z'; ++c){
				B[i][c-'a']+=B[i-1][c-'a'];
			}
		}

		num[0]=1;
		w[0]="-1";
		for (int i=0; i<patt.size(); ++i){
			if (num[i]){
				char ch=patt[i]-'a';
				for (int j=0; j<A[ch].size(); ++j){
					int end=A[ch][j].text.size();
					if (i+end-1<patt.size() && A[ch][j].llet()==patt[i+end-1]){
						bool found=true;
						for (char c='a'; c<='z'; ++c){
							if (A[ch][j].let[c-'a']!=B[max(i,i+end-2)][c-'a']-B[i][c-'a']){
								found=false;
								break;
							}
						}
						if (found){
							if (num[i]<=1 && num[i+end]==0){
								num[i+end]=1;
								w[i+end]=A[ch][j].text;
							}
							else{
								num[i+end]=2;
							}
						}
					}
				}
			}
		}
		if (num.back()==0){
			printf ("impossible\n");
		}
		else if (num.back()>1){
			printf ("ambiguos\n");
		}
		else{
			stack <string> ans;
			int t=num.size()-1;
			while (t>0){
				ans.push(w[t]);
				t-=w[t].size();
			}
			while (!ans.empty()){
				cout<< ans.top() << " ";
				ans.pop();
			}
			printf("\n");
		}
	}

	return 0;
}