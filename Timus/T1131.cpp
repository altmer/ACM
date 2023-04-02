// 1131.cpp : main project file.

#include "stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	int k, n, ans=0, inst = 1;

	cin >> n >> k;

	while (n>inst)
	{
		if (k>=inst)
		{
			++ans;
			inst+=inst;
		}
		else
		{
			ans=ans+(n-inst)/k;
			if ((n-inst)%k != 0)
				++ans;
			inst=n;
		}
	}

	cout << ans;

    return 0;
}
