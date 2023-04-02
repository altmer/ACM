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

string word;
int n;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1007.in", "r", stdin);
	freopen ("T1007.out", "w", stdout);
#endif
	cin >> n;

	while (cin >> word)
	{
		if (word.size()==n)
		{
			int sum=0;
			for (int i=0; i<word.size(); ++i)
				if (word[i]=='1')
					sum+=i+1;
			int t = sum%(n+1);
			if (t==0)
				cout << word << "\n";
			else 
			{
				for (int i=t-1; i<word.size(); i+=(n+1))
					if (word[i]=='1')
					{
						word[i]='0';
						break;
					}
				cout << word << "\n";
			}
		}
		else if (word.size()==n+1)
		{
			int sum=0, num=0, dif;
			for (int i=0; i<word.size(); ++i)
				if (word[i]=='1')
					sum+=i+1;
			
			for (int i=word.size()-1; i>=0; --i)
			{
				if (word[i]=='1')
					dif=i+1+num++;
				else dif=num;
				if ((sum-dif)%(n+1)==0)
				{
					word.erase(i, 1);
					break;
				}
			}
			cout << word << "\n";
		}
		else
		{
			int sum=0, num=0;
			for (int i=0; i<word.size(); ++i)
				if (word[i]=='1')
					sum+=i+1;
			if (sum %(n+1)==0)
			{
				word+="0";
				cout << word << "\n";
			}
			else if ((sum+word.size()+1)%(n+1)==0)
			{
				word+="1";
				cout << word << "\n";
			}
			else
			{
				for (int i=word.size()-1; i>=0; --i)
				{
					if (word[i]=='1')
						++num;
					if ((sum+num)%(n+1)==0)
					{
						word.insert(i, "0");
						break;
					}
					else if ((sum+num+i+1)%(n+1)==0)
					{
						word.insert(i, "1");
						break;
					}
				}
				cout << word << "\n";
			}
		}
	}

	return 0;
}