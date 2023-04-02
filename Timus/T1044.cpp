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


	int n;
	
	cin >> n;
	switch (n)
	{
		case 2 : cout << "10" << endl;
			break;
		case 4 : cout << "670" << endl;
			break;
		case 6 : cout << "55252" << endl;
			break;
		case 8 : cout << "4816030" << endl;
			break; 
	}


    return 0;
}
