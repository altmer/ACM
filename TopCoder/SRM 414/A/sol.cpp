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

class Embassy{
public:
	int visaApplication(vector <int> forms, int day, int op)
	{
		int pos=1;
		long long sum=0;
		int ans=0;
		while (pos<forms.size()){
			sum+=forms[pos];
			if (sum>op){
				sum-=forms[pos];
				break;
			}
			pos++;
		}
		sum+=forms[0];
		int sum2=0;
		// prepare for next day
		if (pos<forms.size()){
			sum2=forms[pos++];
		}
		if (sum2>day-op){
			ans+=sum+sum2;
		}
		else if (sum2){
			ans+=sum+(day-op);
		}
		else{
			ans+=sum;
		}
		sum=0;
		while (pos<forms.size()){
			sum+=forms[pos];
			if (sum>op){
				ans+=day;
				sum=0;
			}
			else if (sum==op){
				ans+=day;
				if (pos+1<forms.size()){
					if (forms[pos+1]<=day-op){
						sum=0;
					}
					else{
						sum=forms[pos+1]-(day-op);
					}
					pos++;
				}
			}
			++pos;
		}
		if (sum){
			if (sum<=op){
				ans+=sum;
			}
			else{
				ans+=day;
			}
		}
		return ans;
	}
};

//declarations
Embassy solve;

void input (void){
	int d[]={4,4,4,4};
	vector <int> a(d,d+4);
	cout << solve.visaApplication(a, 24, 8);
}

void output (void){
}

int main (void)
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	input();
	output();

	return 0;
}