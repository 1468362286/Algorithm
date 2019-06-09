#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
set<set<char> > myset;

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		string s;
		myset.clear();
		for(int i = 0 ; i < n ; i++)
		{
			cin>>s;
			string t="";
			set<char> tmp;
			tmp.clear();
			for(int j = 0 ; j < s.size() ; j++)
			{
				tmp.insert(s[j]);
			}
			myset.insert(tmp);
		}
		cout<<myset.size()<<endl;
		/*
		set<string>::iterator it;
		for(it=myset.begin();it!=myset.end();it++)
			cout<<(*it)<<endl;*/
	}
	return 0;
}

