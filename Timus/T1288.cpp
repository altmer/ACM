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
#include <list>
#include <set>
using namespace std;

int n, D, S1, E1, L1, S2, E2, L2;
double A;
int surf=-1, bott=-1, obj1=-1, obj2=-1;
int cur_obj1=-1, cur_obj2=-1;
bool may_surf, may_bot;
bool sear1, sear2;
double V[10010];

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1288.in", "r", stdin);
	freopen ("T1288.out", "w", stdout);
#endif

	scanf ("%d%d%d%d%d%d%d%d%lf", &n, &D, &S1, &E1, &L1, &S2, &E2, &L2, &A);

	for (int i=0; i<n; ++i){
		scanf ("%lf", &V[i]);
		if (surf==-1){
			if (!may_surf){

				if (V[i]<=35)
					may_surf = true;

			}
			else{
				if (V[i]>=95){
					surf=i;//!!!!!!!!!!!!!!!!!!!!!!!!!!!
				}
			}

		}
		else{

			V[i]*=(1+(double)(i-surf)*A);

			if (V[i]<=35)
				may_bot=true;

			if (i-surf>=D && may_bot){

				if (V[i]>=95){
					bott=i;////////////
					break;
				}

			}

			// first object
			if (i>=surf+S1 && i<=surf+E1){
				sear1=true;
				if (V[i]>=L1){
					if (V[i]>cur_obj1){
						cur_obj1=V[i];
						obj1=i;/////////////////////
					}
				}
			}

			//second object
			if (i>=surf+S2 && i<=surf+E2){
				sear2=true;
				if (V[i]>=L2){
					if (V[i]>cur_obj2){
						cur_obj2=V[i];
						obj2=i;/////////////////////
					}
				}
			}
			
		}
	}

	if (surf!=-1){
		printf ("Surface found at %d.\n", surf+1);
		if (bott!=-1)
			printf ("Bottom found at %d.\n", bott-surf);
		else
			printf ("No bottom.\n");
		if (!sear1)
			printf ("Channel 1: No search.\n");
		else if (obj1!=-1)
			printf ("Channel 1: Object at %d.\n", obj1-surf);
		else
			printf ("Channel 1: No object.\n");

		if (!sear2)
			printf ("Channel 2: No search.\n");
		else if (obj2!=-1)
			printf ("Channel 2: Object at %d.\n", obj2-surf);
		else
			printf ("Channel 2: No object.\n");
	}
	else{
		printf ("No surface.\n");
	}

	return 0;
}