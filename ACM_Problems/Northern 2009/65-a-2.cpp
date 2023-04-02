#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	freopen("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdout);
	cin>>s;
	s='('+s+')';
	int opn=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(')opn++;
		if(opn>0 && s[i]==')')opn--;
	}
	if(opn>0){
		for(int i=0;i<opn;i++)
			s=s+')';
	}
	opn=0;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]==')')opn++;
		if(opn>0 && s[i]=='(')opn--;
	}
	if(opn>0){
		for(int i=0;i<opn;i++)
			s='('+s;
	}

	for(int i=1;i<s.length();i++){
		if(s[i-1]==')' && s[i]==')')
			s.insert(i,"+0");
		if(s[i-1]==')' && s[i]=='(')
			s.insert(i,"+");
		if(s[i-1]=='(' && s[i]==')')
			s.insert(i,"0");
		if(s[i-1]=='(' && s[i]=='+')
			s.insert(i,"0");
		if(s[i-1]=='+' && s[i]==')')
			s.insert(i,"0");
		if(s[i-1]=='+' && s[i]=='+')
			s.insert(i,"0");
	}
	cout<<s<<endl;
	return 0;
}