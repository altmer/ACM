#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <deque>
#include <cmath>
#include <limits>
#include <map>
#include <set>
#include <algorithm>
#pragma comment (linker,"/STACK:65000000")
using namespace std;

int MAXN;
int MAXPEREBOR = 17;
const int HASHSIZE = 999983;
const int MAXSPEED = 1; 
char stad[256][256];
bool path[256][256];
bool myasnaya_kolbasa[256][256];
int sdist[256][256][2*MAXSPEED+1][2*MAXSPEED+1];
char mas[256][256];
int ans=0;
int fx, fy;
int cont = 0;
vector <int> finx;
vector <int> finy;

class pair3{
public:
	int a;
	int b;
	int c;
};

class pair4{
public:
	int a;
	int b;
	int c;
	int d;
};

class pair6{
public:
	unsigned char a;
	unsigned char b;
	 char c;
	 char d;
	 char e;
	 char f;
	 char g;
};

class proveryalko{
	const double INF;
	const double eps;
public:
	proveryalko() : INF(1000*1000*1000),eps(1e-9){}

	bool inside(int x, int y){
		return x>-1 && y>-1 && x<MAXN && y<MAXN;
	}

	bool prov(int x1, int y1, int x2, int y2){
		double dex = 0.5;
		double dey;
		if(x2==x1){
			dey = 0.5*(y2>y1 ? 1 : -1);
			dex = 0;
		}else if(y2==y1){
			dey = 0;
			dex = 0.5*(x2>x1 ? 1 : -1);
		}else if(abs(x2-x1)>abs(y2-y1)){
			dex=0.5*(x2>x1 ? 1 : -1);
			dey=fabs(double(y2-y1)/double(x2-x1)/2.0)*(y2>y1 ? 1 : -1);
		}else{
			dex=fabs(double(x2-x1)/double(y2-y1)/2.0)*(x2>x1 ? 1 : -1);
			dey=0.5*(y2>y1 ? 1 : -1);
		}

		double cx=x1+0.5;
		double cy=y1+0.5;
		double fx=x2+0.5;
		double fy=y2+0.5;
		while(fabs(cx-fx)>eps || fabs(cy-fy)>eps){
			int ix=int(cx+eps),iy=int(cy+eps);
			bool x = fabs(cx-ix)<eps;
			bool y = fabs(cy-iy)<eps;

			if(x&&y){
				if(stad[ix][iy]=='#' || stad[ix][iy-1]=='#' || stad[ix-1][iy]=='#' || stad[ix-1][iy-1]=='#'){
					return false;
				}
			}else if(x){
				if(stad[ix][iy]=='#' || stad[ix-1][iy]=='#'){
					return false;
				}
			}else if(y){
				if(stad[ix][iy]=='#' || stad[ix][iy-1]=='#'){
					return false;
				}
			}else{
				if(stad[ix][iy]=='#')
					return false;
			}

			cx+=dex;
			cy+=dey;
		}
		return stad[x2][y2]!='#';
	}

	bool makepath(int x1, int y1, int x2, int y2){
		double dex = 0.5;
		double dey;
		if(x2==x1){
			dey = 0.5*(y2>y1 ? 1 : -1);
			dex = 0;
		}else if(y2==y1){
			dey = 0;
			dex = 0.5*(x2>x1 ? 1 : -1);
		}else if(abs(x2-x1)>abs(y2-y1)){
			dex=0.5*(x2>x1 ? 1 : -1);
			dey=fabs(double(y2-y1)/double(x2-x1)/2.0)*(y2>y1 ? 1 : -1);
		}else{
			dex=fabs(double(x2-x1)/double(y2-y1)/2.0)*(x2>x1 ? 1 : -1);
			dey=0.5*(y2>y1 ? 1 : -1);
		}

		double cx=x1+0.5;
		double cy=y1+0.5;
		double fx=x2+0.5;
		double fy=y2+0.5;
		while(fabs(cx-fx)>eps || fabs(cy-fy)>eps){
			int ix=int(cx+eps),iy=int(cy+eps);
			bool x = fabs(cx-ix)<eps;
			bool y = fabs(cy-iy)<eps;

			if(x&&y){
				path[ix][iy]=true;
				path[ix][iy-1]=true;
				path[ix-1][iy]=true;
				path[ix-1][iy-1]=true;
			}else if(x){
				path[ix][iy]=true;
				path[ix-1][iy]=true;
			}else if(y){
				path[ix][iy]=true;
				path[ix][iy-1]=true;
			}else{
				path[ix][iy]=true;
			}

			cx+=dex;
			cy+=dey;
		}
		return true;
	}

};



class sobiralko1{
	int dist[256][256];
	int turn[256][256][4];
	int dx[4];
	int dy[4];
	proveryalko prov;
	queue <pair4> qp4;

public:
	sobiralko1(){
		dx[0]=1;
		dx[1]=-1;
		dx[2]=0;
		dx[3]=0;
		dy[0]=0;
		dy[1]=0;
		dy[2]=1;
		dy[3]=-1;
	}

	void sbfs(int sx, int sy){
		pair4 hru, u;
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				for(int k=0;k<2*MAXSPEED+1;k++){
					for(int l=0;l<2*MAXSPEED+1;l++){
						sdist[i][j][k][l]=1000000;
					}
				}
			}
		}
		hru.a=sx;
		hru.b=sy;
		hru.c=MAXSPEED;
		hru.d=MAXSPEED;
		sdist[sx][sy][MAXSPEED][MAXSPEED]=0;
		qp4.push(hru);
		while(!qp4.empty()){
			u=qp4.front();
			qp4.pop();
			for(int x =-1;x<2;x++){
				for(int y = -1;y<2;y++){
					if(u.c+x<2*MAXSPEED+1 && u.c+x>-1 && u.d+y<2*MAXSPEED+1 && u.d+y>-1){
						if(prov.inside(u.a+u.c+x-MAXSPEED, u.b+u.d+y-MAXSPEED)){
							if(sdist[u.a+u.c+x-MAXSPEED][u.b+u.d+y-MAXSPEED][u.c+x][u.d+y] > sdist[u.a][u.b][u.c][u.d]+1){
								if(prov.prov(u.a, u.b, u.a+u.c+x-MAXSPEED, u.b+u.d+y-MAXSPEED)){
									sdist[u.a+u.c+x-MAXSPEED][u.b+u.d+y-MAXSPEED][u.c+x][u.d+y] = sdist[u.a][u.b][u.c][u.d]+1;
									hru.c=u.c+x;
									hru.d=u.d+y;
									hru.a=hru.c+u.a-MAXSPEED;
									hru.b=hru.d+u.b-MAXSPEED;
									qp4.push(hru);
									cont++;									
								}
							}
						}
					}
				}
			}
		}
	}

public:
	void create(){
		ifstream fin("stadium.txt");
		ofstream fout("bugoga1.txt");
		int sx,sy;
		fin >> MAXN >> MAXN;
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				fin >> stad[i][j];
				mas[i][j]=stad[i][j];
				if(stad[i][j]=='O'){
					stad[i][j]='.';
					finx.push_back(i);
					finy.push_back(j);
				}
			}
		}
		sbfs(0 , 0);
		int mx = 1000000000;
		pair4 w;
		for(int k=0;k<finx.size();k++){
			for(int i=0;i<2*MAXSPEED+1;i++){
				for(int j=0;j<2*MAXSPEED+1;j++){
					if(sdist[finx[k]][finy[k]][i][j]<mx){
						mx = sdist[finx[k]][finy[k]][i][j];//поиск минимума в финише
						w.a=finx[k];
						w.b=finy[k];
						w.c=i;
						w.d=j;
					}
				}
			}
		}
		fx=w.a;
		fy=w.b;
		ans=mx;
		pair4 pred;
		bool fnd=false;
		path[0][0]=true;
		path[0][1]=true;
		path[0][2]=true;
		path[0][3]=true;
		path[0][4]=true;
		path[0][5]=true;
		path[0][6]=true;
		path[0][7]=true;
		do{
			path[w.a][w.b]=true;
			pred = w;
			w.a-=(w.c-MAXSPEED);
			w.b-=(w.d-MAXSPEED);
			prov.makepath(w.a, w.b, pred.a, pred.b);//восстановление маршрута по родителям
			for(int i=w.c-1;i<w.c+2;i++){
				fnd=false;
				for(int j=w.d-1;j<w.d+2;j++){
					if(i>-1 && i<2*MAXSPEED+1 && j>-1 && j<2*MAXSPEED+1){
						if(sdist[w.a][w.b][i][j]==mx-1){
							w.c=i;
							w.d=j;
							mx--;
							fnd=true;
							break;							
						}
					}
				}
				if(fnd)break;
			}			
		}while(w.a!=0 || w.b!=0);
		//O#O
		//###
		//O#O - кисть для мясной колбасы
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				for(int k=-1;k<2;k++){
					for(int l=-1;l<2;l++){
						if(path[i][j]){
							myasnaya_kolbasa[i][j]=true;
							if(prov.inside(i+k, j+l)){
								if(prov.prov(i,j,i+k,j+l)){
									if(abs(i)!=abs(j)){
										myasnaya_kolbasa[i+k][j+l]=true;
									}
								}
							}
						}
					}
				}
			}
		}
				
		fout << fx << " " << fy << " ";
		
		fin.close();
		fout.close();
	}
};

bool newpath[256][256];


class vodilko1{
	proveryalko prov;
	unsigned short int pgrad[256][256];
	pair <int, int> q[65536];
	int qps;
	int qpf;
	
	pair <int, int> bfs(int sx, int sy, int ex, int ey){
		unsigned short int *p = &pgrad[0][0];
		for(int i=0;i<256*256;i++){
			*(p+i)=65535;
		}
		bool *p2 =&newpath[0][0];
		for(int i=0;i<256*256;i++){
			*(p2+i)=false;
		}
		qps=qpf=0;
		q[qpf++]=make_pair(sx, sy);
		pgrad[sx][sy]=0;
		pair <int, int> u;
		pair <int, int> tmp;
		while(qps^qpf){
			u=q[qps++];
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(i!=0 || j!=0){
						tmp.first=u.first+i;
						tmp.second=u.second+j;
						if(prov.inside(tmp.first, tmp.second) && stad[tmp.first][tmp.second]!='#'){
							if(pgrad[tmp.first][tmp.second]>pgrad[u.first][u.second]+1){
								pgrad[tmp.first][tmp.second]=pgrad[u.first][u.second]+1;
								q[qpf++]=tmp;
							} 
						}
					}
				}
			}
		}
		int mn = 1000000;
		pair <int, int> minfin;
		for(int i=0; i<finx.size(); ++i){
			if(pgrad[finx[i]][finy[i]]<mn && (finx[i]!=ex || finy[i]!=ey)){
				mn = pgrad[finx[i]][finy[i]];
				minfin = make_pair(finx[i],finy[i]);
			}
		}
		
		return minfin;
	}

	void path_grad(int sx, int sy){
		unsigned short int *p = &pgrad[0][0];
		for(int i=0;i<256*256;i++){
			*(p+i)=65535;
		}
		qps=qpf=0;
		q[qpf++]=make_pair(sx, sy);
		pgrad[sx][sy]=0;
		pair <int, int> u;
		pair <int, int> tmp;
		while(qps^qpf){
			u=q[qps++];
			/*if(qps == 65536){
				qps++;
			}*/
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(i!=0 || j!=0){
						tmp.first=u.first+i;
						tmp.second=u.second+j;
						if(prov.inside(tmp.first, tmp.second)){
							if(path[tmp.first][tmp.second]){
								if(pgrad[tmp.first][tmp.second]>pgrad[u.first][u.second]+1){
									pgrad[tmp.first][tmp.second]=pgrad[u.first][u.second]+1;
									q[qpf++]=tmp;
									/*if(qpf == 65536){
										qpf++;
									}*/
								}
							} 
						}
					}
				}
			}
		}
	}

	void kol_grad(int sx, int sy){
		qps=0;
		qpf=0;
		q[qpf++]=make_pair(sx, sy);
		pair <int, int> u;
		pair <int, int> tmp;
		while(qps^qpf){
			u=q[qps++];
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(i!=0 || j!=0){
						tmp.first=u.first+i;
						tmp.second=u.second+j;
						if(prov.inside(tmp.first, tmp.second)){
							if(myasnaya_kolbasa[tmp.first][tmp.second]){
								if(pgrad[tmp.first][tmp.second]>pgrad[u.first][u.second]+1 || (pgrad[tmp.first][tmp.second]>=pgrad[u.first][u.second]+1 && path[tmp.first][tmp.second])){
									pgrad[tmp.first][tmp.second]=pgrad[u.first][u.second]+1;
									path[tmp.first][tmp.second]=false;
									q[qpf++]=tmp;
								/*	if(qpf == 65536){
										qpf++;
									}*/
								}
							}
						}
					}
				}
			}
		}
	}
	
	pair6 qu[100000];
	pair <int, int > best;
	bool h[HASHSIZE];
	
	long long hash; 
	void perebor(){
		pair6 u;
		int mn = 1000000000;
		while(qpf^qps){
			u=qu[qps++];
			if(pgrad[u.a][u.b]<mn){
				mn=pgrad[u.a][u.b];
				best = make_pair(u.e, u.f);
			}
			
			if(u.g>MAXPEREBOR-1){
				return;
			}
			
			u.g++;
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(u.c+i<MAXPEREBOR && u.c+i>-MAXPEREBOR && u.d+j<MAXPEREBOR && u.d+j>-MAXPEREBOR){
						if(prov.inside(u.a+u.c+i, u.b+u.d+j)){
							if(pgrad[u.a][u.b] >= pgrad[u.a+u.c+i][u.b+u.d+j] && myasnaya_kolbasa[u.a+u.c+i][u.b+u.d+j]){
								if(prov.prov(u.a, u.b, u.a+u.c+i, u.b+u.d+j)){
									u.c+=i;
									u.d+=j;
									u.a+=u.c;
									u.b+=u.d;
									hash = 1;
									hash <<= 4;
									hash+=u.a;
									hash <<= 4;
									hash+=u.b;
									hash <<= 4;
									hash+=u.c;
									hash+=128;
									hash <<= 4;
									hash+=u.d;
									hash+=128;
									hash%=HASHSIZE;
									if(!h[hash]){
										h[hash]=true;
										qu[qpf++]=u;
									}
									u.a-=u.c;
									u.b-=u.d;
									u.c-=i;
									u.d-=j;							
								}	
							}
						}
					}
				}
			}
		}
	}

	void pokolbase(int x, int y, int sx, int sy){
		path_grad(fx, fy);
		kol_grad(fx, fy);
		
		pair6 hru;
		hru.a = x;
		hru.b = y;
		hru.c = sx;
		hru.d = sy;
		qps = 0;
		qpf = 0;
		for(int i=-1;i<2;i++){
			for(int j=-1;j<2;j++){
				if(hru.c+i<MAXPEREBOR && hru.c+i>-MAXPEREBOR && hru.d+j<MAXPEREBOR && hru.d+j>-MAXPEREBOR){
					if(prov.inside(x+sx+i, y+sy+j)){
						if(prov.prov(x, y, x+sx+i, y+sy+j)){
							hru.c+=i;
							hru.d+=j;
							hru.a+=hru.c;
							hru.b+=hru.d;
							hru.e=i;
							hru.f=j;
							hru.g=1;
							qu[qpf++]=hru;
							hru.a-=hru.c;
							hru.b-=hru.d;
							hru.c-=i;
							hru.d-=j;						
						}	
					}
				}
			}
		}

		for(int i=0;i<HASHSIZE;i++){
			h[i]=false;
		}

		perebor();
		
	//	ofstream brrout("bugoga1.txt");
	///*	for(int i=0;i<MAXN;i++){
	//		for(int j=0;j<MAXN;j++){
	//			brrout.width(8);
	//			brrout << pgrad[i][j];
	//		}
	//		brrout<< endl;
	//	}*/
	//	brrout.close();
		
	}

	void make_newpath(pair <int , int> u){
		bool found;
		unsigned short int grad = 0; 
		pair <int, int> oldstep = make_pair(-1, -1);
		pair <int, int> oldstep2 = make_pair(-1, -1);
		while(true){
			found = false;
			for(int i=-1;i<2 && !found;i++){
				for(int j=-1;j<2 && !found;j++){
					if(prov.inside(u.first+i, u.second+j)){
						if(pgrad[u.first][u.second]>pgrad[u.first+i][u.second+j]){
							pgrad[u.first][u.second] = grad++;
							oldstep2 = oldstep;
							oldstep = u;
							u=make_pair(u.first+i, u.second+j);
							newpath[u.first][u.second]=true;
							found = true;
						}
					}
				}
			}
			if(oldstep2.first!=-1){
				if(prov.inside(oldstep2.first+1, oldstep2.second)){
					newpath[oldstep2.first+1][oldstep2.second]=true;
					pgrad[oldstep2.first+1][oldstep2.second] = grad-2;
				}
				if(prov.inside(oldstep2.first-1, oldstep2.second)){
					newpath[oldstep2.first-1][oldstep2.second]=true;
					pgrad[oldstep2.first-1][oldstep2.second] = grad-2;
				}
				if(prov.inside(oldstep2.first, oldstep2.second+1)){
					newpath[oldstep2.first][oldstep2.second+1]=true;
					pgrad[oldstep2.first][oldstep2.second+1] = grad-2;
				}
				if(prov.inside(oldstep2.first, oldstep2.second-1)){
					newpath[oldstep2.first][oldstep2.second-1]=true;
					pgrad[oldstep2.first][oldstep2.second-1] = grad-2;
				}
			}
			if(!found)break;
			
		}
		pgrad[u.first][u.second] = grad++;
		newpath[u.first][u.second]=true;
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				if(!newpath[i][j])pgrad[i][j]=65535;
			}
		}
		/*ofstream brrout("bugoga1.txt");
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				brrout.width(8);
				brrout << pgrad[i][j];
			}
			brrout<< endl;
		}
		brrout.close();*/
	}

	void perebornepokolbase(){
		for(int i=0;i<HASHSIZE;i++){
			h[i]=false;
		}
		pair6 u;
		int mn = 1000000000;
		while(qpf^qps){
			u=qu[qps++];
			if(pgrad[u.a][u.b]<mn){
				mn=pgrad[u.a][u.b];
				best = make_pair(u.e, u.f);
			}
			
			if(u.g>MAXPEREBOR-1){
				return;
			}
			
			u.g++;
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(u.c+i<MAXPEREBOR && u.c+i>-MAXPEREBOR && u.d+j<MAXPEREBOR && u.d+j>-MAXPEREBOR){
						if(prov.inside(u.a+u.c+i, u.b+u.d+j)){
							if(pgrad[u.a][u.b] >= pgrad[u.a+u.c+i][u.b+u.d+j] && newpath[u.a+u.c+i][u.b+u.d+j]){
								if(prov.prov(u.a, u.b, u.a+u.c+i, u.b+u.d+j)){
									u.c+=i;
									u.d+=j;
									u.a+=u.c;
									u.b+=u.d;
									hash = 1;
									hash <<= 4;
									hash+=u.a;
									hash <<= 4;
									hash+=u.b;
									hash <<= 4;
									hash+=u.c;
									hash+=128;
									hash <<= 4;
									hash+=u.d;
									hash+=128;
									hash%=HASHSIZE;
									if(!h[hash]){
										h[hash]=true;
										qu[qpf++]=u;
									}
									u.a-=u.c;
									u.b-=u.d;
									u.c-=i;
									u.d-=j;							
								}	
							}
						}
					}
				}
			}
		}		
	}
	
public:
	void drive(int x, int y, int sx, int sy, int ex, int ey, int &ew, int& sn){
		if(ex>-1 && ex<1000){
			char st = stad[ex][ey]; 
			stad[ex][ey]='#';
			pokolbase(x,y,sx,sy);
			stad[ex][ey]=st;			
		}else if(ex == -1){
			pokolbase(x,y,sx,sy);
		}else {
			ex-=1000;
			ey-=1000;
			if(ex==fx && ey==fy){
				pair <int, int> newfin = bfs(sx, sy, ex, ey);
				make_newpath(newfin);
				//прикрутить проверку достижимости другого финиша
				//убрать ужас написанный нижеы
				bool found=false;
				pair6 hru;
				hru.a = x;
				hru.b = y;
				hru.c = sx;
				hru.d = sy;
				qps = 0;
				qpf = 0;
				if(x == 126){
					qpf = 0;
				}
				for(int i=-1;i<2;i++){
					for(int j=-1;j<2;j++){
						if(hru.c+i<MAXPEREBOR && hru.c+i>-MAXPEREBOR && hru.d+j<MAXPEREBOR && hru.d+j>-MAXPEREBOR){
							if(prov.inside(x+sx+i,y+sy+j) && prov.prov(x, y, x+sx+i,y+sy+j)){
								if(pgrad[x+sx+i][y+sy+j]<65535){
									found = true;
									hru.c+=i;
									hru.d+=j;
									hru.a+=hru.c;
									hru.b+=hru.d;
									hru.e=i;
									hru.f=j;
									hru.g=1;
									qu[qpf++]=hru;
									hru.a-=hru.c;
									hru.b-=hru.d;
									hru.c-=i;
									hru.d-=j;						
								}
							}
						}
					}
				}
				if(found)perebornepokolbase();
				else{
					if(sx>0) best.first=-1;
					else if(sx<0)best.first=1;
					else best.first=0;
					if(sy>0) best.second=-1;
					else if(sy<0)best.second=1;
					else best.second=0;
				}
			}else{
				char st = stad[ex][ey]; 
				stad[ex][ey]='#';
				pokolbase(x,y,sx,sy);
				stad[ex][ey]=st;						
			}
		}
		if(best.first==1){
			sn='n';
		}else if(best.first==-1){
			sn='s';
		}else{
			sn=' ';
		}
		if(best.second==1){
			ew='e';
		}else if(best.second==-1){
			ew='w';
		}else{
			ew=' ';
		}
	}
};

sobiralko1 obj;

int main(){
	MAXN = 256;
	obj.create();
	vodilko1 drovino;
	int a,b;
	int sx=0,sy=0;
	int vx=0, vy=0;
	bool fin = false;
	ans=0;
	for(int i=0;i<100 && !fin;i++){
		mas[sx][sy]='*';
		drovino.drive(sx,sy,vx,vy,1251,1012,a,b);
		ans++;
		if(b == 'n')vx++;
		if(b == 's')vx--;
		sx+=vx;
		if(a == 'w')vy--;
		if(a == 'e')vy++;
		sy+=vy;
		if(sx == 251 && sy == 41){
		fin=true;
		}

	}
	freopen("bugoga.txt","w",stdout);
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			printf("%c",mas[i][j]);
			//if(!myasnaya_kolbasa[i][j])printf("%c",mas[i][j]);else printf("*");
			//if(!path[i][j])printf("%c",mas[i][j]);else printf("*");
			//if(!newpath[i][j])printf("%c",mas[i][j]);else printf("*");


		}
		printf("\n");
	}
	if(fin){
	cout << "Finished after " << ans << " steps." << endl;
	cout << cont;
	}else cout << "Bugoga!!!!!!!!" << endl;
	return 0;
}