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
#include <limits>
#include <map>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

const int black=1;
const int white=2;
const int fre=0;
int n;
short ptr, st, end;
vector <int> ans;
vector <int> grid;
bool fin;

void rec2 (){
	if(fin)
		return;
	if(st==end){
		fin=true;
		return;
	}
	if(ptr==end){
		if(grid[ptr-1]==black){
			ans.push_back(ptr-1);
			grid[ptr]=black;
			grid[ptr-1]=fre;
			ptr--;
			end--;
			fin=true;
			return;
		}
		else if(grid[ptr-2]==black && grid[ptr-1]==white){
			ans.push_back(ptr-2);
			grid[ptr]=black;
			grid[ptr-2]=fre;
			ptr-=2;
			end--;
			fin=true;
			return;
		}
	}
	else if(ptr==st){
		if(grid[ptr+1]==white){
			ans.push_back(ptr+1);
			grid[ptr]=white;
			grid[ptr+1]=fre;
			ptr++;
			st++;
			fin=true;
			return;
		}
		else if(grid[ptr+2]==white && grid[ptr+1]==black){
			ans.push_back(ptr+2);
			grid[ptr]=white;
			grid[ptr+2]=fre;
			ptr+=2;
			st++;
			fin=true;
			return;
		}
	}
	else{
		if(ptr-st>=2 && grid[ptr-2]==black && grid[ptr-1]==white){
			ans.push_back(ptr-2);
			grid[ptr]=black;
			grid[ptr-2]=fre;
			if(!(ptr+1<=end && grid[ptr+1]==black)){
				ptr-=2;
				rec2( );
				if(fin)return;
				ptr+=2;
			}
			if(fin)return;
			grid[ptr]=fre;
			grid[ptr-2]=black;
			ans.pop_back();
		}
		if (end-ptr>=2 && grid[ptr+1]==black && grid[ptr+2]==white){
			ans.push_back(ptr+2);
			grid[ptr]=white;
			grid[ptr+2]=fre;
			if(!(ptr-1>=st && grid[ptr-1]==white)){
				ptr+=2;
				rec2();
				if(fin)return;
				ptr-=2;
			}
			if(fin)return;
			grid[ptr]=fre;
			grid[ptr+2]=white;
			ans.pop_back();
		}
		if (grid[ptr+1]==white){
			ans.push_back(ptr+1);
			grid[ptr]=white;
			grid[ptr+1]=fre;
			if(!(ptr-1>=st && grid[ptr-1]==white)){
				ptr++;
				rec2();
				if(fin)return;
				ptr--;
			}
			if(fin)return;
			grid[ptr]=fre;
			grid[ptr+1]=white;
			ans.pop_back();
		}
		if(grid[ptr-1]==black){
			ans.push_back(ptr-1);
			grid[ptr]=black;
			grid[ptr-1]=fre;
			if(!(ptr+1<=end && grid[ptr+1]==black)){
				ptr--;
				rec2();
				if(fin)return;
				ptr++;
			}
			grid[ptr]=fre;
			grid[ptr-1]=black;
			ans.pop_back();
		}
	}
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1474.in", "r", stdin);
	freopen ("T1474.out", "w", stdout);
#endif
	
	ans.reserve(1000000);

	scanf ("%d", &n);

	grid.resize(2*n+1);
	st=0;
	end=grid.size()-1;
	ptr=n;

	for (int i=0; i<n; ++i){
		grid[i]=black;
	}

	for (int i=n+1; i<grid.size(); ++i){
		grid[i]=white;
	}

	while(st!=end){
		fin=false;
		rec2();
	}

	printf ("%d\n", ans.size()); 
	for (int i=0; i<ans.size(); ++i){
		printf ("%d ", ans[i]);
	}

	return 0;
}