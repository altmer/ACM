#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int n = 0;
string line;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1567.in", "r", stdin);
	freopen ("T1567.out", "w", stdout);
#endif

	getline (cin, line);

	for (int i=0; i<line.size(); ++i)
	{
		switch (line[i])
		{
		case 'a': n+=1;
			break;
		case 'b': n+=2;
			break;
		case 'c': n+=3;
			break;
		case 'd': n+=1;
			break;
		case 'e': n+=2;
			break;
		case 'f': n+=3;
			break;
		case 'g': n+=1;
			break;
		case 'h': n+=2;
			break;
		case 'i': n+=3;
			break;
		case 'j': n+=1;
			break;
		case 'k': n+=2;
			break;
		case 'l': n+=3;
			break;
		case 'm': n+=1;
			break;
		case 'n': n+=2;
			break;
		case 'o': n+=3;
			break;
		case 'p': n+=1;
			break;
		case 'q': n+=2;
			break;
		case 'r': n+=3;
			break;
		case 's': n+=1;
			break;
		case 't': n+=2;
			break;
		case 'u': n+=3;
			break;
		case 'v': n+=1;
			break;
		case 'w': n+=2;
			break;
		case 'x': n+=3;
			break;
		case 'y': n+=1;
			break;
		case 'z': n+=2;
			break;
		case '.': n+=1;
			break;
		case ',': n+=2;
			break;
		case '!': n+=3;
			break;
		case ' ': n+=1;
			break;
		}
	}

	cout << n;

	return 0;
}