#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
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
#include <limits>
#include <map>
#include <list>
#include <set>
#pragma comment(linker, "/STACK:65777216")
using namespace std;

const int INF = 1000*1000*1000;

struct per{
    vector<int> p;
    int cd;

    per() : p(vector<int>(5)), cd(-1) {}
    per (int* arr) : p(vector<int>(5)), cd(-1){
        p[0]=arr[0];
        p[1]=arr[1];
        p[2]=arr[2];
        p[3]=arr[3];
        p[4]=arr[4];
    }
    
    int code(){
        return cd==-1 ? cd=p[0]*10000+p[1]*1000+p[2]*100+p[3]*10+p[4] : cd;
    }

    per move(int fr, int to){
        per ret;
        if(fr==0){
            if(to==1){
                ret.p[0]=p[3];
                for (int i=0; i<3; ++i)
                    ret.p[i+1]=p[i];
                ret.p[4]=p[4];
            }else{
                ret.p[0]=p[3];
                ret.p[1]=p[4];
                for (int i=0; i<3; ++i)
                    ret.p[i+2]=p[i];
            }
        }else if(fr==1){
            if(to==0){
                for (int i=0; i<3; ++i)
                    ret.p[i]=p[i+1];
                ret.p[3]=p[0];
                ret.p[4]=p[4];
            }else{
                ret.p[0]=p[0];
                ret.p[1]=p[4];
                for (int i=0; i<3; ++i)
                    ret.p[i+2]=p[i+1];
            }
        }else{
            if(to==0){
                for (int i=0; i<3; ++i)
                    ret.p[i]=p[i+2];
                ret.p[3]=p[0];
                ret.p[4]=p[1];
            }else{
                ret.p[0]=p[0];
                for (int i=0; i<3; ++i)
                    ret.p[i+1]=p[i+2];
                ret.p[4]=p[1];
            }
        }
        return ret;
    }
};

struct Edge{
    int item, next;
    pair<int,int> act;
    
    Edge() : item(-1), next(-1) {}
};

int c;
int arr[501], n;
pair<int,int> ans[1000];
int cnt=0;
Edge A[60000], E[1000000];
pair<int,int> pp[60000];
int par[60000], dist[60000];
int nume=0;
bool exist[60000];

void move(int fr){
    int t1=arr[fr];
    int t2=arr[fr+1];
    int t3=arr[fr+2];
    for (int i=fr-1; i>=0; --i){
        arr[i+3]=arr[i];
    }
    arr[0]=t1;
    arr[1]=t2;
    arr[2]=t3;
}

void shift(){
    for (int i=1; i<n;++i){
        arr[i-1]=arr[i]-1;
    }
}

void construct_graph(per st){
    per q[1000];
    int qh = 0, qt = 0;
    q[qt++] = st;
    exist[st.code()]=true;
    while(qt != qh){
        st = q[qh++];
        int u=st.code();
        for (int j=0; j<3; ++j){
            for (int i=0; i<3; ++i){
                if(i==j) continue;
                per nw = st.move(j,i);
                int wh=nw.code();
                if(!exist[wh]){ q[qt++]=nw; exist[wh]=true;}
                
                E[nume].act = make_pair(c+j+1, c+i);
                E[nume].item=wh;
                E[nume].next=A[u].next;
                A[u].next=nume++;
            }
        }
    }
}

int bfs(int st){
    int q[10000];
    int qh=0, qt=0;
    q[qt++]=st;
    dist[st]=0;
    while(qh!=qt){
        int u = q[qh++];
        for (int w=A[u].next; w!=-1; w=E[w].next){
            int v = E[w].item;
            if(dist[u]+1<dist[v]){
                dist[v]=dist[u]+1;
                par[v]=u;
                pp[v]=E[w].act;
                q[qt++]=v;
            }
        }
    }
}

int main (void){
    freopen ("polonius.in", "r", stdin);
    freopen ("polonius.out", "w", stdout);

    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }

    c=0;
    for (; n>5; n--){
        int ind=-1;
        for (int i=0; i<n; ++i){
            if(arr[i]==1){
                ind=i;
                break;
            }
        }
        if(ind>=n-2){
            ans[cnt++] = make_pair(c+n-2, c);
            move(n-3);
            ind=ind==n-2 ? 1 : 2;
        }
        move(ind);
        ans[cnt++] = make_pair(c+ind+1, c);
        shift();
        c++;
    }

    // graph
    per st = per(arr);
    construct_graph(st);
    for (int i=0; i<60000; ++i)
        dist[i]=INF;
    bfs(st.code());

    int fin=12345;

    pair<int,int> s[6];
    int T=0;

    while(fin!=st.code()){
        s[T++]=pp[fin];
        fin=par[fin];
    }

    for (int i=T-1; i>=0; --i){
        ans[cnt++]=s[i];
    }

    printf("%d\n", cnt);
    for (int i=0; i<cnt; ++i){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}