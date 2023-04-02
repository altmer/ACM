#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

long long n;
long long ans=0;
string s;
long long m[13][109][109];

bool isluck(long long x){
	long long s=0;
	long long t=x;
	while(x>0){
		s+=x%10;
		x/=10;
	}
	return(!(t%s));	
}

int main(){
	freopen("just.in","r",stdin);
	freopen("just.out","w",stdout);
	cin >> n;
	if(n==1000000000000){
		ans++;
		n--;
	}
	ostringstream oss;
	oss << n;
	s=oss.str();
	int msum=s.size()*9;
	msum++;
	for(int sumDig=1;sumDig<msum;sumDig++){
		for(int pos=0;pos<s.size();pos++){
			for(int sum=0;sum<=sumDig;sum++){
				for(int mod=0;mod<sumDig;mod++){
					m[pos][sum][mod]=0;
				}
			}
		}
		m[0][0][0]=1;
		for(int pos=0;pos<s.size();pos++){
			for(int sum=0;sum<=sumDig;sum++){
				for(int mod=0;mod<sumDig;mod++){
					for(int d=0;d<10;d++){
						if(m[pos][sum][mod]==0){
							continue;
						}
						m[pos+1][sum+d][(10*mod+d)%sumDig]+=m[pos][sum][mod];
					}
				}
			}
		}
		//
		for(int pos=0;pos<s.size();pos++){
			int cursum=0;
			int curval=0;
			int sum=0;
			int val=0;
			for(int i=0;i<pos;i++){
				sum+=s[i]-'0';
				val=(10*val+(s[i]-'0'))%sumDig;
			}
			for(int dig=0;dig<(s[pos]-'0');dig++){
				cursum=sumDig-sum-dig;
				if(cursum<0){
					continue;
				}
				curval=(10*val+dig)%sumDig;
				for(int i=pos+1;i<s.size();i++){
				curval=(10*curval)%sumDig;
				}
				int si=s.size();
				curval=(sumDig-curval)%sumDig;
				ans+=m[si-pos-1][cursum][curval];
			}
			
		}

	}
	if(isluck(n))ans++;
	cout << ans;
	return 0;
}