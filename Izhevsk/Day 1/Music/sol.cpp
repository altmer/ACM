#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
vector<int> chords[18];
map<string,int> chname;
map<string,int> note;
string sost("xxxxxx");
int chord;
int base;
int n;
int struna[7];
vector<int> notes;
bool pressed[7];

void fill();

bool check(){
	bool bad=false;
	int mn=n,mx=0;
	for(int i=0;i<notes.size();i++)
		pressed[i]=false;
	for(int i=0;i<6;i++)if(sost[i]!='x'){
		int sound=(sost[i]-'0'+struna[i])%12;
		bool found=false;
		for(int j=0;j<notes.size();j++){
			if(notes[j]==sound){
				pressed[j]=true;
				found=true;
			}
		}
		if(!found)bad=true;
		//pressed[sound]=true;
		if(sost[i]!='0'){
			mn=min(mn,sost[i]-'0');
			mx=max(mx,sost[i]-'0');
		}
	}
	bool ok=true;
	for(int i=0;i<notes.size();i++)
		if(!pressed[i])ok=false;
	if(mx-mn>3)ok=false;
	return !bad && ok;
}

void rec(int ind){
	if(ind==6){
		if(check())
			cout<<sost<<endl;
		return;
	}
	for(int i=-1;i<=n;i++){
		char let;
		if(i==-1)
			let='x';
		else let='0'+i;
		sost[ind]=let;
		rec(ind+1);
	}
}

void run(){
	notes=chords[chord];
	for(int i=0;i<notes.size();i++)
		notes[i]=(notes[i]+base)%12;
	rec(0);
}

void minorize(){
	for(int i=0;i<chords[chord].size();i++)
		if(chords[chord][i]==4)
			chords[chord][i]=3;
}

int main(){
	freopen("music.in","r",stdin);
	freopen("music.out","w",stdout);
	fill();
	cin>>n;
	string t;
	for(int i=0;i<6;i++){
		cin>>t;
		struna[i]=note[t];
	}
	string tmp;
	scanf("\n");
	getline(cin,tmp);
	tmp+=" end";
	istringstream iss(tmp);
	
	iss>>t;
	base=note[t];
	iss>>t;
	bool minor=false;
	if(t=="m"){
		minor=true;
		iss>>t;
	}
	chord=chname[t];
	if(minor)
		minorize();
	run();
}

void fill(){
	chords[0].push_back(0);
	chords[0].push_back(4);
	chords[0].push_back(7);

	chords[1].push_back(0);
	chords[1].push_back(3);
	chords[1].push_back(7);

	chords[2].push_back(0);
	chords[2].push_back(4);
	chords[2].push_back(7);
	chords[2].push_back(11);

	chords[3].push_back(0);
	chords[3].push_back(4);
	chords[3].push_back(7);
	chords[3].push_back(10);
	
	chords[4].push_back(0);
	chords[4].push_back(4);
	chords[4].push_back(7);
	chords[4].push_back(9);

	chords[5].push_back(0);
	chords[5].push_back(4);
	chords[5].push_back(7);
	chords[5].push_back(8);

	chords[6].push_back(0);
	chords[6].push_back(4);
	chords[6].push_back(7);
	chords[6].push_back(6);

	chords[7].push_back(0);
	chords[7].push_back(4);
	chords[7].push_back(7);
	chords[7].push_back(5);

	chords[8].push_back(0);
	chords[8].push_back(4);
	chords[8].push_back(7);
	chords[8].push_back(2);

	chords[9].push_back(0);
	chords[9].push_back(3);
	chords[9].push_back(6);
	chords[9].push_back(9);

	chords[10].push_back(0);
	chords[10].push_back(4);
	chords[10].push_back(7);
	chords[10].push_back(11);
	chords[10].push_back(2);

	chords[11].push_back(0);
	chords[11].push_back(4);
	chords[11].push_back(7);
	chords[11].push_back(11);
	chords[11].push_back(2);
	chords[11].push_back(5);

	chords[12].push_back(0);
	chords[12].push_back(4);
	chords[12].push_back(7);
	chords[12].push_back(11);
	chords[12].push_back(2);
	chords[12].push_back(5);
	chords[12].push_back(9);

	chords[13].push_back(0);
	chords[13].push_back(4);
	chords[13].push_back(8);

	chords[14].push_back(0);
	chords[14].push_back(4);
	chords[14].push_back(6);

	chords[15].push_back(0);
	chords[15].push_back(7);

	chords[16].push_back(0);
	chords[16].push_back(2);
	chords[16].push_back(7);

	chords[17].push_back(0);
	chords[17].push_back(5);
	chords[17].push_back(7);

	note["C"]=0;
	note["C#"]=1;
	note["D"]=2;
	note["D#"]=3;
	note["E"]=4;
	note["F"]=5;
	note["F#"]=6;
	note["G"]=7;
	note["G#"]=8;
	note["A"]=9;
	note["A#"]=10;
	note["B"]=11;

	chname["end"]=0;
	chname["7+"]=2;
	chname["7"]=3;
	chname["6"]=4;
	chname["5+"]=5;
	chname["5-"]=6;
	chname["4"]=7;
	chname["2"]=8;
	chname["dim"]=9;
	chname["9"]=10;
	chname["11"]=11;
	chname["13"]=12;
	chname["aug"]=13;
	chname["-"]=14;
	chname["5"]=15;
	chname["sus2"]=16;
	chname["sus4"]=17;
}