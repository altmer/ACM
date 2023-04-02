// T1068.cpp : main project file.

#include "stdafx.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	int n;
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	cin >> n;
	int sum = 0;
	for (int i=min(1,n);i<=max(1,n);++i)
		sum+=i;
	cout << sum;	
    return 0;
}
