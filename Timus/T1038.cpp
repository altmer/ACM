// T1038.cpp : main project file.

#include "stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string word;
int i, ans = 0;
bool inword = false, insent = false;

int main(void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
		
	while (cin >> word)
	{
		inword = false;
		for (int i=0; i!=word.size();++i)
		{
			if (ispunct(word[i]))
			{
				inword=false;
				if (word[i]=='.' || word[i]=='!' || word[i]=='?')
					insent=false;
			}
			if (isalpha(word[i]))
			{
				if (!insent && islower(word[i]))
					++ans;
				if (inword && isupper(word[i]))
					++ans;
				inword=true;
				insent=true;
			}
		}
	}

	cout << ans << endl;

    return 0;
}
