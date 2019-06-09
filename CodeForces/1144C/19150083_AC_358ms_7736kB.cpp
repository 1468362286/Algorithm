#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
map<int,int>mymap;
vector<int>Add,Sub;
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,x;
	while(cin>>n)
	{
		mymap.clear();
		int flag=0;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x,mymap[x]++;
			if(mymap[x]>2)
				flag=1;
		}
		if(flag)
		{
			cout<<"NO"<<endl;
			continue;
		}
		map<int,int>::iterator it;
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			x = (*it).first;
			if((*it).second==2)
			{
				Add.push_back(x);
				Sub.push_back(x);
			}
			else 
			{
				Add.push_back(x);
			}
		}
		cout<<"YES"<<endl;
		cout<<Add.size()<<endl;
		for( i = 0 ; i < Add.size() ; i++)
		{
			cout<<Add[i]<<" ";
		}
		cout<<endl;
		cout<<Sub.size()<<endl;
		for( i = Sub.size()-1 ; i >=0 ; i--)
			cout<<Sub[i]<<" ";
		cout<<endl;
	}
	return 0;
}	