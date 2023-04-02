#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

enum op{B_RIGHT, IN, LEFT, RIGHT};
string s;
vector <vector <int> > A, O;

bool right (string &x){
	stack <char> t;
	for (int i=0; i<x.size(); ++i){
		if (x[i]=='(' || x[i]=='['){
			t.push(x[i]);
		}
		else if (x[i]==')'){
			if (!t.empty() && t.top()=='(')
				t.pop();
			else
				return false;
		}
		else{
			if (!t.empty() && t.top()=='[')
				t.pop();
			else
				return false;
		}
	}
	return t.empty();		
}

string print (int i, int j){
	if (i>j)
		return "";
	switch (O[i][j]){
		case B_RIGHT: 
			return s.substr(i, j-i+1);
		case IN: 
			return s[i]+print(i+1, j-1)+s[j];
		case LEFT:
			return s[i]+print(i+1, j)+(s[i]=='(' ? ')' : ']');
		case RIGHT:
			return (s[j]==')' ? '(' : '[')+print(i, j-1)+s[j];
		default: 
			return print(i, O[i][j]-10000) + print (O[i][j]-10000+1, j);
	}	
	return "";
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1183.in", "r", stdin);
	freopen ("T1183.out", "w", stdout);
#endif

	getline (cin, s);
	if (s.empty()){
		cout << s;
		return 0;
	}
	A.resize(s.size());
	O.resize(s.size());
	for (int i=0; i<A.size(); ++i){
		A[i].assign(s.size(), 10000);
		O[i].assign(s.size(), -1);
	}

	for (int l=1; l<=s.size(); ++l){
		for (int i=0; i<s.size()-l+1; ++i){
			int j=i+l-1;
			// склеить
			for (int k=i; k<j; ++k){
				if (A[i][k]+A[k+1][j]<A[i][j]){
					A[i][j]=A[k+1][j]+A[i][k];
					O[i][j]=k+10000;
				}
			}
			// watch
			string w=s.substr(i, j-i+1);
			if (right(w)){
				if (w.size()<=A[i][j]){
					A[i][j]=w.size();
					O[i][j]=B_RIGHT;
				}
			}
			else if (w[0]=='('){
				if (w[w.size()-1]==')'){
					if (A[i][j]>A[i+1][j-1]+2){
						A[i][j]=A[i+1][j-1]+2;
						O[i][j]=IN;
					}
				}
				else if ((i+1>j ? 2 : A[i+1][j]+2)<A[i][j]){
					A[i][j]=w.size()+1;
					O[i][j]=LEFT;
				}
			}
			else if (w[0]=='['){
				if (w[w.size()-1]==']'){
					if (A[i][j]>A[i+1][j-1]+2){
						A[i][j]=A[i+1][j-1]+2;
						O[i][j]=IN;
					}
				}
				else if ((i+1>j ? 2 : A[i+1][j]+2)<A[i][j]){
					A[i][j]=w.size()+1;
					O[i][j]=LEFT;
				}
			}
			else if (w[w.size()-1]==')'){
				if ((i>j-1 ? 2 : A[i][j-1]+2)<A[i][j]){
					A[i][j]=w.size()+1;
					O[i][j]=RIGHT;
				}
			}
			else if (w[w.size()-1]==']'){
				if ((i>j-1 ? 2 : A[i][j-1]+2)<A[i][j]){
					A[i][j]=w.size()+1;
					O[i][j]=RIGHT;
				}
			}
		}
	}

	cout << print (0, s.size()-1);
	
	return 0;
}