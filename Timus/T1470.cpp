#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
using namespace std;

struct coord{
	int x, y, z;
	coord(){
		x=y=z=0;
	}
	coord (int _x, int _y, int _z){
		x=_x;y=_y;z=_z;
	}
};

int A[130][130][130];
int n;

void updateZ (int x, int y, int z, int v)
{
	while (z<=n){
		A[x][y][z]+=v;
		z += (z & -z);
	}
}

void updateYZ (int x, int y, int z, int v)
{
	while (y<=n){
		updateZ(x, y, z, v);
		y += (y & -y);
	}
}

void update (int x, int y, int z, int v)
{
	while (x<=n){
		updateYZ(x, y, z, v);
		x += (x & -x);
	}
}

int readZ (int x, int y, int z)
{
	int sum=0;
	while (z>0){
		sum+=A[x][y][z];
		z-= (z & -z);
	}
	return sum;
}


int readYZ (int x, int y, int z)
{
	int sum=0;
	while (y>0){
		sum+=readZ(x, y, z);
		y-= (y & -y);
	}
	return sum;
}

int read (int x, int y, int z)
{
	int sum=0;
	while (x>0){
		sum+=readYZ(x, y, z);
		x-= (x & -x);
	}
	return sum;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1470.in", "r", stdin);
	freopen ("T1470.out", "w", stdout);
#endif

	scanf ("%d", &n);

	int quer=-1;
	while (true){
		scanf ("%d", &quer);
		int k;
		int ans=0;
		int t1, t2, t3, t4, t5, t6, t7, t8;
		t1=t2=t3=t4=t5=t6=t7=t8=0;
		int cnt;
		coord st, end;
		switch (quer){
			case 1:
				scanf ("%d%d%d%d", &st.x, &st.y, &st.z, &k);
				update(st.x+1, st.y+1, st.z+1, k);
				break;
			case 2:
				scanf ("%d%d%d%d%d%d", &st.x, &st.y, &st.z, &end.x,&end.y,&end.z);
				st.x++;st.y++;st.z++;end.x++;end.y++;end.z++;
				t1=read(end.x, end.y, end.z);
				cnt=0;
				if (st.x>1){
					st.x--;
					t2=read(st.x, end.y, end.z);
				}
				if (st.y>1){
					st.y--;
					t3=read(end.x, st.y, end.z);
				}
				if (st.z>1){
					st.z--;
					t4=read(end.x, end.y, st.z);
				}
				if (t2 && t3){
					t5=read(st.x, st.y, end.z);
				}
				if (t2 && t4){
					t6=read(st.x, end.y, st.z);
				}
				if (t3 && t4){
					t7=read(end.x, st.y, st.z);
				}
				if (t5 && t6 && t7){
					t8=read(st.x, st.y, st.z);
				}
				printf ("%d\n", t1-t2-t3-t4+t5+t6+t7-t8);
				break;
			case 3:
				return 0;
			default:
				return 0;
		}
	}

	return 0;
}