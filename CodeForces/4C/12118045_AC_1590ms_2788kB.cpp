#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>
using namespace std;

map<string,int> mymap;

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int n;
	while(cin>>n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			cin>>s;
			if(mymap.find(s)==mymap.end())
			{
				mymap[s]++;
				cout<<"OK"<<endl;
			}
			else
			{
				cout<<s<<mymap[s]<<endl;
				mymap[s]++;
			}
		}
	}
	return 0;
}