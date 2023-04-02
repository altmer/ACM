#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<limits>
#include<cmath>
using namespace std;
string s;
int score=0;
bool bad=false;
int rec(int pos,int left){
	if(left==0)return 0;
	if(pos<s.length()){
		if(s[pos]==' ' || s[pos]=='|')return rec(pos+1,left);
		int cur=0;
		if(s[pos]>='1' && s[pos]<='9')cur=s[pos]-'0';
		if(s[pos]=='X')cur=10;
		if(s[pos]=='/')cur=-10;
		int next=0;
		if(left)next+=rec(pos+1,left-1);
		if(next==-10)cur=10;
		else cur+=next;
		return cur;
	}
	else return 0;
}
void solve(){
	if(3*9+3>=s.length()){
		bad=true;
		return;
	}
	for(int i=0;!bad && i<10;i++){
		int curscore=0;
		if(s[i*3]!='|')bad=true;
		int j=i*3+1;
		string samp="987654321-X";
		if(samp.find(s[j])==-1)bad=true;
		bool strike=false;
		if(s[j]=='X')strike=true;
		samp="987654321-/";
		j++;
		if(s[j-1]>='1' && s[j-1]<='9'){
			samp.erase(0,s[j-1]-'0');
			curscore+=s[j-1]-'0';
		}
		if(i!=9 && strike)samp=" ";
		else if(i==9 && strike)samp="987654321-X";
		if(samp.find(s[j])==-1)bad=true;
		bool spare=false;
		if(s[j]=='/')spare=true;
		if(s[j]>='1' && s[j]<='9'){
			curscore+=s[j]-'0';
		}
		if(strike)curscore=10+rec(j,2);
		else if(spare)curscore=10+rec(j+1,1);
		if(i==9 && (spare || strike)){
			j++;
			if(spare || s[j-1]=='X')samp="987654321-X";
			else samp="987654321-/";
			if(s[j-1]>='1' && s[j-1]<='9')samp.erase(0,s[j-1]-'0');
			if(samp.find(s[j])==-1)bad=true;
		}
		if(j+1>=s.length() || s[j+1]!='|')bad=true;
		if(i==9 && j+2!=s.length())bad=true;
		score+=curscore;
	}
}
int main(void){
	// COMMENT THIS!!!!!!!!!!!!!!!!!!!!
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	char c='a';
	while(c!='\n' && scanf("%c",&c)!=EOF){
		if(c!='\n')s+=c;
	}
	solve();	
	if(bad)cout<<"NO\n";
	else {
		cout<<"YES\n";
		cout<<score;
	}
	return 0;
}