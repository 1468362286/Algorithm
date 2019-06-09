#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> myset;
int main()
{
	//freopen("in.txt","r",stdin);
	string s1,s2;
	while(cin>>s1>>s2)
	{	
		myset.clear();
		for(int i = 1 ; i <= s1.size() ; i++)
		{
			string tmp="";
			tmp+=s1.substr(0,i);
			for(int j = 1 ; j <= s2.size() ; j++)
			{
				tmp+=s2.substr(0,j);
				myset.insert(tmp);
			}		
		}
		cout<<*(myset.begin())<<endl;
	}
	return 0;
}