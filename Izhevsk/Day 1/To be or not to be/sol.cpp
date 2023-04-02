#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits>
using namespace std;

int mas[100][100];
ifstream fin("toBeOrNotToBe.in");
ofstream fout("toBeOrNotToBe.out");

int main(){
	//freopen("toBeOrNotToBe.in","r",stdin);
	//freopen("toBeOrNotToBe.out","w",stdout);
	
	int n,k,s;
	fin>>n>>k>>s;
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++){
			if(s>0){
				mas[i][j]=1;
				s--;
			}
			else mas[i][j]=0;
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fout<<mas[i%k][j%k];
			if(j<n-1)fout<<" ";
		}
		fout<<endl;
	}
	return 0;
}
