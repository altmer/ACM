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

class Pattern{
protected:
	vector <string> str;
	vector <int> pos;
	
	bool endWith (int num, const string& word){
		if (word.size()>=str[num].size()){
			for (int i=(int)word.size()-str[num].size(), j=0; i<word.size(); ++i, ++j){
				if (tolower(word[i])!=str[num][j])
					return false;
			}
			return true;
		}
		return false;
	}
public:
	void init (int n){
		str.reserve(n);
		pos.reserve(n);
	}

	void addPattern (string s){
		int sep=-1;
		for (int i=0; i<s.size(); ++i){
			if (isalpha(s[i])){
				s[i]=tolower(s[i]);
			}
			else if (s[i]=='-'){
				sep=i;
			}
		}
		if (sep!=-1){
			str.push_back(s.substr(0, sep)+s.substr(sep+1));
			pos.push_back(sep);
		}
	}
	int find (const string& word, int len){
		int ans=-1;
		for (int i=0; i<str.size(); ++i){
			if (endWith(i, word)){
				int onLine=(int)word.size()-(int)str[i].size() + pos[i];
				if (onLine<=len && ans<onLine){
					ans=onLine;
				}
			}
		}
		return ans;
	}
};

int n;
Pattern solve;
string line, ans;
char ch;

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1257.in", "r", stdin);
	freopen ("T1257.out", "w", stdout);
#endif

	scanf ("%d", &n);
	getline (cin, line);
	solve.init(n);

	for (int i=0; i<n; ++i){
		getline (cin, line);
		solve.addPattern(line);
	}

	while (getline (cin, line)){
		ans.clear();
		ans.reserve(2*line.size());

		int beg_line=0;
		int beg_word=-1;
		bool inword=false;

		for (int i=0; i<line.size(); ++i){
			if (!inword && isalpha(line[i])){
				inword=true;
				beg_word=i;
			}
			else if (inword && !isalpha(line[i])){
				inword=false;
				beg_word=-1;
			}

			if (i-beg_line==39){
				// work
				if(!inword){
					ans+=line.substr(beg_line, 40)+"\n";
					beg_line=i+1;
				}
				else{
					int end_word=i;
					while (end_word<line.size() && isalpha(line[end_word]))
						++end_word;
					if (i==end_word-1){
						ans+=line.substr(beg_line, end_word-beg_line);
						beg_line=end_word;
						if (end_word<line.size())
							ans+="\n";
					}
					else{
						int len=i-beg_word;
						i=end_word-1;
						ans+=line.substr(beg_line, beg_word-beg_line);

						string word = line.substr(beg_word, end_word-beg_word);
						int w = solve.find (word, len);
						
						if (w==-1){
							ans+="\n"/*+word*/;
							beg_line=beg_word;
						}
						else{
							ans+=word.substr(0, w)+"-\n"/*+word.substr(w)*/;
							beg_line=beg_word+w;
						}
					}

					inword=false;
					beg_word=-1;

				}
			}

			// end for
		}

		if (beg_line<line.size()){
			ans+=line.substr(beg_line);
		}

		cout << ans << "\n";

		// end while
	}

	return 0;
}