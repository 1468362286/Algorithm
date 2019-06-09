#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
map<int,int>mymap;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,x;
	while(cin>>n>>m)
	{
		mymap.clear();
		for( i = 0 ; i < m ; i++)
			cin>>x,mymap[x]++;
		map<int,int>::iterator it;
		/*
		for( it = mymap.begin() ; it!=mymap.end() ; it++)
		{
			cout<<(*it).first<<" "<<(*it).second<<endl;
		}*/		
		int cnt=0;
		int ans=0;
		for( i = 1 ; i <= 100 ; i++)
		{
			int sum=0;
			map<int,int>::iterator it;
			for( it = mymap.begin() ; it!=mymap.end() ; it++)
			{
				int x = (*it).first;
				int y = (*it).second;
				sum+=y/i;
			}
			if(sum>=n)
			{
				ans=max(ans,i);
			}
		}
		cout<<ans<<endl;		
	}
	return 0;
}