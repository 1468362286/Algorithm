#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> mymap;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s;
	while(cin>>n)
	{
		mymap.clear();
		cin>>s;
		for( i = 0 ; i < n-1 ; i++)
		{
			string tmp = s.substr(i,2);
		//	string tmp=s[i]+s[i+1];
			mymap[tmp]++;
		}
		int maxi=0;
		string ans;
		map<string,int>::iterator it;
		for(it=mymap.begin();it!=mymap.end();it++)
		{
			if(maxi<(*it).second)
			{
				ans=(*it).first;
				maxi=(*it).second;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}