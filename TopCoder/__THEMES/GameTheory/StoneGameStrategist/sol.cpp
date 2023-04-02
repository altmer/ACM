#include <string> 
#include <vector> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
 
#define sz size()
#define pb push_back
#define VI vector < int >
#define VS vector < string >
#define ALL(a) a.begin(),a.end()
 
using namespace std; 
 
int sg(VI a)
  {int q1,c1=0;
  
  for(q1=0;q1<a.sz;q1+=2)c1=c1^a[q1];
  
  return c1;}
 
VI comp(VI a)
{
  int q1,c1;
  VI b;
 
  b.pb(a[0]);
  for(q1=1;q1<a.sz;q1++)
	  b.pb(a[q1]-a[q1-1]);
  reverse(ALL(b));
  return b;}
 
class StoneGameStrategist 
{public:
string play(vector <int> piles) 
  {
  int q1,q2,s,k,found=0,c1;
 
  for(q2=1;q2<=1000;q2++)for(q1=0;q1<piles.sz;q1++)
    {
    VI kk=piles;
 
    kk[q1]-=q2;
    
    if(kk[q1]<0)continue;
    if(q1!=0 && kk[q1]<kk[q1-1])continue;
 
    c1=sg(comp(kk));
    if(c1==0 && found==0)
      {found=1;
      s=q2;
      k=q1;}
    }
 
  string ret;
 
  if(found==0)ret="YOU LOSE";
  else
    {
    char dd[100];
    sprintf(dd,"TAKE %d STONES FROM PILE %d",s,k);
    ret=dd;
    }
 
  return ret;}};

//declarations


void input (void){
}

void output (void){
}

int main (void)
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	input();
	output();

	return 0;
}