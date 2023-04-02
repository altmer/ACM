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

map <string, int> orig, cop;
string line, s;
int n;

int get_num (string s){
	int res=0;
	int p=1;
	for (int i=s.size()-1; i>=0; --i){
		res+=(s[i]-'0')*p;
		p*=10;
	}
	if (res==0)
		res=1;
	return res;
}

map <string, int> work (string &s){
	map <string, int> ans;
	int pos=0;
	while (pos<s.size()){
		// getting sequence
		int end=pos;
		while (end<s.size() && s[end]!='+'){
			end++;
		}
		string seq=s.substr(pos, end-pos);
		//getting coef
		pos=end+1;
		end=0;
		while (isdigit(seq[end])){
			end++;
		}
		int coef=get_num(seq.substr(0, end));
		seq.erase(0, end);
		// splitting levels
		vector <int> lev(seq.size(), 0), mult (seq.size(), 1);
		int cur=0;
		for (int i=0; i<seq.size(); ++i){
			if (seq[i]=='('){
				cur++;
			}
			else if (seq[i]==')'){
				cur--;
			}
			lev[i]=cur;
		}
		// finding multiples
		for (int i=0; i<lev.size(); ++i){
			if (lev[i]>0){
				int j=i+1;
				while (lev[j]!=lev[i]-1)
					++j;
				int p=j+1;
				int k;
				while (p<seq.size() && isdigit(seq[p]))
					++p;
				if (p>j+1){
					k=get_num(seq.substr(j+1, p-j-1));
				}
				else{
					k=1;
				}
				for (int l=i; l<j; ++l){
						mult[l]*=k;
						lev[l]--;
				}
			}
		}
		// processing elements
		end=0;
		while (end<seq.size()){
			if (isupper(seq[end])){
				int p=end+1;
				while (p<seq.size() && islower(seq[p]))
					p++;
				string el=seq.substr(end, p-end);
				int k=p;
				while (k<seq.size() && isdigit(seq[k]))
					k++;
				int num=get_num(seq.substr(p, k-p))*mult[end]*coef;
				end=k;
				ans[el]+=num;
			}
			else{
				end++;
			}
		}
	}
	return ans;
}

int main (void){
#ifndef ONLINE_JUDGE
	freopen ("T1186.in", "r", stdin);
	freopen ("T1186.out", "w", stdout);
#endif

	getline (cin, line);
	orig=work(line);
	scanf ("%d\n", &n);
	for (int i=0; i<n; ++i){
		bool res=true;
		cop.clear();
		getline (cin, s);
		cop=work(s);
		if (cop.size()!=orig.size()){
			res=false;
		}
		if  (res){
			for (map <string, int> ::iterator it=orig.begin(); it!=orig.end(); ++it){
				string el=it->first;
				int num=it->second;
				if (cop[el]!=num){
					res=false;
					break;
				}
			}
		}
		if (res){
			cout << line << "=="<< s << "\n";
		}
		else{
			cout << line << "!=" << s<< "\n";
		}
	}

	return 0;
}