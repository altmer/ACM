#include <iostream>
#include <string>
using namespace std;

const int err=-1;
const int sig=1;
const int trun=2;
const int frac=3;
const int exp=4;
const int exi=5;
const string oops="Not a floating point number";
char sign;
string TM, FM;
__int64 E;
string ans, line, word;
int prec, sw;

int getsign (int pos)
{
	if (pos<line.size()&&line[pos]=='+')
	{
		sign='+';
		pos++;
		if (pos<line.size()&&isdigit(line[pos]))
		{
			sw=trun;
		}
		else if (pos<line.size()&&line[pos]=='.')
		{
			pos++;
			sw=frac;
		}
		else
			sw=err;
	}
	else if (pos<line.size()&&line[pos]=='-')
	{
		sign='-';
		pos++;
		if (pos<line.size()&&isdigit(line[pos]))
		{
			sw=trun;
		}
		else if (pos<line.size()&&line[pos]=='.')
		{
			pos++;
			sw=frac;
		}
		else
			sw=err;
	}
	else if (pos<line.size()&&isdigit (line[pos]))
	{
		sign='+';
		sw=trun;
	}
	else if (pos<line.size()&&line[pos]=='.')
	{
		sign='+';
		pos++;
		if (pos<line.size()&&isdigit(line[pos]))
			sw=frac;
		else
			sw=err;
	}
	else
		sw=err;
	return pos;
}
int gettrun (int pos)
{
	while (pos<line.size() && isdigit(line[pos]))
		TM+=line[pos++];

	if (pos==line.size())
	{
		sw=exi;
	}
	else if (line[pos]=='.')
	{
		pos++;
		if (pos<line.size()&&isdigit(line[pos]))
			sw=frac;
		else
			sw=err;
	}
	else if (toupper(line[pos])=='E')
	{
		pos++;
		if (pos<line.size() && (isdigit(line[pos])||line[pos]=='-' || line[pos]=='+'))
			sw=exp;
		else
			sw=err;
	}
	else
		sw=err;
	return pos;
}

void getexp (int pos)
{
	char T[200];
	int j=0, m=1;
	if (line[pos]=='-')
	{
		m=-1;
		pos++;
	}
	else if (line[pos]=='+')
		pos++;
	if (pos==line.size())
	{
		sw=err;
		return;
	}
	else
	for (int i=pos; i<line.size(); ++i)
	{
		if (isdigit(line[i]))
			T[j++]=line[i];
		else
		{
			sw=err;
			return;
		}
	}
	int i=0;
	while (T[i]=='0')
		++i;
	if (j-i>4)
		E=1000;
	else
		E=atol(T);
	E*=m;
	sw=exi;
}

int getfrac (int pos)
{
	if (pos>=line.size())
	{
		sw=err;
		return 0;
	}
	while (pos<line.size() && isdigit(line[pos]))
		FM+=line[pos++];

	if (pos==line.size())
	{
		sw=exi;
	}
	else if (toupper(line[pos])=='E')
	{
		pos++;
		if (pos<line.size() && (isdigit(line[pos])||line[pos]=='-' || line[pos]=='+'))
			sw=exp;
		else
			sw=err;
	}
	else
		sw=err;
	return pos;
}

void set_zero(void)
{
	ans="";
	TM="";
	FM="";
	E=0;
}

int main (void)
{
#ifndef ONLINE_JUDGE
	freopen ("T1074.in", "r", stdin);
	freopen ("T1074.out", "w", stdout);
#endif

	while (getline(cin, line))
	{
		int i=0;
		if (line=="#")
			break;
		cin >> prec;
		getline (cin, word);
				
		set_zero();

		sw=sig;
		for (int i=0; i<line.size(); ++i)
			if (isspace(line[i]))
				sw=err;

		while (sw!=exi)
		{
			switch (sw)
			{
			case sig: i=getsign(i);
				break;
			case trun: i=gettrun(i);
				break;
			case frac: i=getfrac(i);
				break;
			case exp: getexp(i);
				break;
			case err: ans=oops;
				sw=exi;
				break;
			}
		}
		if (ans.empty())
		{
			if (E>0)
			{
				for (int i=1; i<=E; ++i)
				{
					if (!FM.empty())
					{
						TM+=FM[0];
						FM.erase(0, 1);
					}
					else
						TM+="0";
				}
			}
			else if (E<0)
			{
				if (E>200)
					FM="0";
				else
					for (int i=1; i<=abs(E); ++i)
						if (!TM.empty())
						{
							string word;
							word+=TM[TM.size()-1];
							FM.insert(0, word);
							TM.erase(TM.size()-1,1);
						}
						else
							FM.insert(0, "0");
			}

			bool res=false;
			int i=0;
			while (i<TM.size()&&TM[i]=='0')
				++i;
			
			if (sign=='-')
			{
				ans+=sign;
			}
			

			for (i; i<TM.size();++i)
			{
				ans+=TM[i];
				res=true;
			}
			if (!res)
				ans+="0";
			
			if (prec)
			{
				ans+=".";
				for (int i=0; i<prec; ++i)
				{
					if (i<FM.size())
					{
						ans+=FM[i];
						if (FM[i]!='0')
							res=true;
					}
					else
						ans+="0";
				}
			}
			if (!res && ans[0]=='-')
				ans.erase(0, 1);
		}
		cout << ans;
		printf ("\n");
	}

	return 0;
}