#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> s, h, g, r;
string sur, faq;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1446.in", "r", stdin);
	freopen ("T1446.out", "w", stdout);
#endif

	int n;
	scanf("%d\n", &n);
	for (int i=1; i<=n; ++i)
	{
		getline(cin,sur);
		getline(cin, faq);
		switch (faq[0])
		{
		case 'S': s.push_back(sur);
			break;
		case 'H': h.push_back(sur);
			break;
		case 'G': g.push_back(sur);
			break;
		case 'R': r.push_back(sur);
			break;
		}
	}
	printf ("Slytherin:\n");
	for (vector <string> :: iterator i=s.begin(); i!=s.end(); ++i)
		cout << *i << endl;
	printf("\nHufflepuff:\n");
	for (vector <string> :: iterator i=h.begin(); i!=h.end(); ++i)
		cout << *i << endl;
	printf ("\nGryffindor:\n");
	for (vector <string> :: iterator i=g.begin(); i!=g.end(); ++i)
		cout << *i << endl;
	printf ("\nRavenclaw:\n");
	for (vector <string> :: iterator i=r.begin(); i!=r.end(); ++i)
		cout << *i << endl;
	return 0;
}