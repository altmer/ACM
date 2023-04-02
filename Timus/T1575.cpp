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
#include <set>
using namespace std;

class Metro{
protected:
	map <string, int> met;
	vector <vector <int> > A;
	vector <int> dist;
public:
	Metro(){
		A.resize(80);
		//red
		met["7_klyuchei"]=0;
		met["Sortirovochnaya"]=1;
		A[0].push_back(1);
		A[1].push_back(0);
		met["China_town"]=2;
		A[1].push_back(2);
		A[2].push_back(1);
		met["Zarechny"]=3;
		A[2].push_back(3);
		A[3].push_back(2);
		met["City"]=4;
		A[3].push_back(4);
		A[4].push_back(3);
		met["1905_year_square"]=5;
		A[4].push_back(5);
		A[5].push_back(4);
		met["Kuybyshevskaya"]=6;
		A[5].push_back(6);
		A[6].push_back(5);
		met["Sibirskaya"]=7;
		A[6].push_back(7);
		A[7].push_back(6);
		met["Siniye_kamni"]=8;
		A[7].push_back(8);
		A[8].push_back(7);
		met["Lechebnaya"]=9;
		A[8].push_back(9);
		A[9].push_back(8);
		met["Varshavskaya"]=10;
		A[9].push_back(10);
		A[10].push_back(9);
		met["Kompressornaya"]=11;
		A[10].push_back(11);
		A[11].push_back(10);
		met["Koltsovo"]=12;
		A[11].push_back(12);
		A[12].push_back(11);
		// yellow
		met["Zelyony_ostrov"]=13;
		met["Tatishchevskaya"]=14;
		A[13].push_back(14);
		A[14].push_back(13);
		met["Verh_Isetskaya"]=15;
		A[14].push_back(15);
		A[15].push_back(14);
		met["Kommunarov_square"]=16;
		A[15].push_back(16);
		A[16].push_back(15);
		// 	met["1905_year_square"]=5;
		A[16].push_back(5);
		A[5].push_back(16);
		met["Teatralnaya"]=17;
		A[17].push_back(5);
		A[5].push_back(17);
		met["Vostochnaya"]=18;
		A[17].push_back(18);
		A[18].push_back(17);
		met["Vtuzgorodok"]=19;
		A[18].push_back(19);
		A[19].push_back(18);
		met["Kamennye_palatki"]=20;
		A[19].push_back(20);
		A[20].push_back(19);
		met["University"]=21;
		A[20].push_back(21);
		A[21].push_back(20);
		// purple
		met["MEGA"]=22;
		met["Metallurgov"]=23;
		A[22].push_back(23);
		A[23].push_back(22);
		met["Kraulya"]=24;
		A[23].push_back(24);
		A[24].push_back(23);
		met["Central_stadium"]=25;
		A[24].push_back(25);
		A[25].push_back(24);
		met["Moskovskaya"]=26;
		A[25].push_back(26);
		A[26].push_back(25);
		// 	met["1905_year_square"]=5;
		A[26].push_back(5);
		A[5].push_back(26);
		met["Shevchenko"]=27;
		A[5].push_back(27);
		A[27].push_back(5);
		met["Pionerskaya"]=28;
		A[27].push_back(28);
		A[28].push_back(27);
		met["Turbinnaya"]=29;
		A[28].push_back(29);
		A[29].push_back(28);
		met["Elmash"]=30;
		A[29].push_back(30);
		A[30].push_back(29);
		met["Taganskaya"]=31;
		A[30].push_back(31);
		A[31].push_back(30);
		// deep blue
		met["Akademicheskaya"]=32;
		met["Yugo_zapadnaya"]=33;
		A[32].push_back(33);
		A[33].push_back(32);
		met["Volgogradskaya"]=34;
		A[33].push_back(34);
		A[34].push_back(33);
		met["Posadskaya"]=35;
		A[34].push_back(35);
		A[35].push_back(34);
		met["Geologicheskaya"]=36;
		A[35].push_back(36);
		A[36].push_back(35);
		// met["Teatralnaya"]=17;
		A[36].push_back(17);
		A[17].push_back(36);
		met["Gagarinskaya"]=37;
		A[17].push_back(37);
		A[37].push_back(17);
		met["Komsomolskaya"]=38;
		A[37].push_back(38);
		A[38].push_back(37);
		met["Shefskaya"]=39;
		A[38].push_back(39);
		A[39].push_back(38);
		met["Ozyornaya"]=40;
		A[39].push_back(40);
		A[40].push_back(39);
		met["Italyanskaya"]=41;
		A[40].push_back(41);
		A[41].push_back(40);
		met["Kalinovskaya"]=42;
		A[41].push_back(42);
		A[42].push_back(41);
		// orange
		met["Sovhoznaya"]=43;
		met["Voennaya"]=44;
		A[43].push_back(44);
		A[44].push_back(43);
		met["Aviatsionnaya"]=45;
		A[44].push_back(45);
		A[45].push_back(44);
		met["Dvorets_sporta"]=46;
		A[45].push_back(46);
		A[46].push_back(45);
		//met["Geologicheskaya"]=36;
		A[46].push_back(36);
		A[36].push_back(46);
		//met["Kuybyshevskaya"]=6;
		A[36].push_back(6);
		A[6].push_back(36);
		//met["Vostochnaya"]=18;
		A[6].push_back(18);
		A[18].push_back(6);
		//met["Gagarinskaya"]=37;
		A[18].push_back(37);
		A[37].push_back(18);
		met["Vilonovskaya"]=47;
		A[37].push_back(47);
		A[47].push_back(37);
		// light blue 
		met["Keramicheskaya"]=48;
		met["Vtorchermet"]=49;
		A[48].push_back(49);
		A[49].push_back(48);
		met["Samolyotnaya"]=50;
		A[49].push_back(50);
		A[50].push_back(49);
		met["Botanicheskaya"]=51;
		A[50].push_back(51);
		A[51].push_back(50);
		met["Parkovaya"]=52;
		A[51].push_back(52);
		A[52].push_back(51);
		met["Mayakovskaya"]=53;
		A[52].push_back(53);
		A[53].push_back(52);
		met["Oborony_square"]=54;
		A[53].push_back(54);
		A[54].push_back(53);
		//met["Kuybyshevskaya"]=6;
		A[54].push_back(6);
		A[6].push_back(54);
		// met["Teatralnaya"]=17;
		A[6].push_back(17);
		A[17].push_back(6);
		//met["Shevchenko"]=27;
		A[17].push_back(27);
		A[27].push_back(17);
		met["Uralskaya"]=55;
		A[27].push_back(55);
		A[55].push_back(27);
		met["Zvezda"]=56;
		A[55].push_back(56);
		A[56].push_back(55);
		met["I_Pyatiletki_square"]=57;
		A[56].push_back(57);
		A[57].push_back(56);
		met["Pobedy"]=58;
		A[57].push_back(58);
		A[58].push_back(57);
		// green
		met["Himmash"]=59;
		met["Nizhne_Isetskaya"]=60;
		A[59].push_back(60);
		A[60].push_back(59);
		met["Uktusskie_Gory"]=61;
		A[60].push_back(61);
		A[61].push_back(60);
		met["Shcherbakovskaya"]=62;
		A[61].push_back(62);
		A[62].push_back(61);
		//met["Botanicheskaya"]=51;
		A[62].push_back(51);
		A[51].push_back(62);
		met["Chkalovskaya"]=63;
		A[51].push_back(63);
		A[63].push_back(51);
		met["Bazhovskaya"]=64;
		A[63].push_back(64);
		A[64].push_back(63);
		//met["Geologicheskaya"]=36;
		A[64].push_back(36);
		A[36].push_back(64);
		// 	met["1905_year_square"]=5;
		A[36].push_back(5);
		A[5].push_back(36);
		met["Dinamo"]=65;
		A[5].push_back(65);
		A[65].push_back(5);
		// met["Uralskaya"]=55;
		A[65].push_back(55);
		A[55].push_back(65);
		met["Mashinostroiteley"]=66;
		A[55].push_back(66);
		A[66].push_back(55);
		met["Uralmash"]=67;
		A[66].push_back(67);
		A[67].push_back(66);
		met["Prospekt_Kosmonavtov"]=68;
		A[67].push_back(68);
		A[68].push_back(67);
		met["Bakinskih_Komissarov"]=69;
		A[68].push_back(69);
		A[69].push_back(68);
		// brown
		// met["Kommunarov_square"]=16;
		// met["City"]=4;
		A[16].push_back(4);
		A[4].push_back(16);
		// met["Uralskaya"]=55;
		A[4].push_back(55);
		A[55].push_back(4);
		// met["Pionerskaya"]=28;
		A[55].push_back(28);
		A[28].push_back(55);
		// met["Gagarinskaya"]=37;
		A[28].push_back(37);
		A[37].push_back(28);
		// met["Vtuzgorodok"]=19;
		A[37].push_back(19);
		A[19].push_back(37);
		//met["Sibirskaya"]=7;
		A[19].push_back(7);
		A[7].push_back(19);
		//met["Oborony_square"]=54;
		A[7].push_back(54);
		A[54].push_back(7);
		// met["Bazhovskaya"]=64;
		A[54].push_back(64);
		A[64].push_back(54);
		//met["Dvorets_sporta"]=46;
		A[64].push_back(46);
		A[46].push_back(64);
		//met["Posadskaya"]=35;
		A[46].push_back(35);
		A[35].push_back(46);
		//met["Moskovskaya"]=26;
		A[35].push_back(26);
		A[26].push_back(35);
		//met["Kommunarov_square"]=16;
		A[26].push_back(16);
		A[16].push_back(26);
	}
	int path (const string& st1, const string& st2){
		int p1 = met[st1];
		int p2 = met[st2];
		dist.assign(80, 1000000000);
		queue <int> q;
		q.push(p1);
		dist[p1]=0;
		while (!q.empty()){
			int u=q.front();
			q.pop();
			if (u==p2)
				break;
			for (int i=0; i<A[u].size(); ++i){
				int v=A[u][i];
				if (dist[v]>dist[u]+1){
					dist[v]=dist[u]+1;
					q.push(v);
				}
			}
		}
		return dist[p2];
	}
};

int n;
string t1, t2;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1575.in", "r", stdin);
	freopen ("T1575.out", "w", stdout);
#endif

	Metro E;
	scanf ("%d", &n);

	for (int i=0; i<n; ++i){
		cin >> t1 >> t2;
		printf ("%d\n", E.path(t1, t2));
	}

	return 0;
}