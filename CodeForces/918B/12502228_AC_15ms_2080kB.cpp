#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,string> mymap;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i;
	string s1,s2;
	while(cin>>n>>m)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>s1>>s2;
			mymap[s2]=s1;
		}
		for( i = 0 ; i < m ; i++)
		{
			cin>>s1>>s2;
			string tmp = s2.substr(0,s2.size()-1);
			cout<<s1<<" "<<s2<<" #"<<mymap[tmp]<<endl;
		}
	}
	return 0;
}