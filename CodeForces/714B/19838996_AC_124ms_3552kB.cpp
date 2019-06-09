#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 100010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
int a[maxn];
map<int,int>mymap;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
			cin>>a[i],mymap[a[i]]++;
		if(mymap.size()<=3)
		{
			if(mymap.size()==3)
			{
				map<int,int>::iterator it;
				vector<int>vec;
				for( it = mymap.begin() ; it!=mymap.end() ; ++it)
				{
					vec.push_back((*it).first);
				}
				if(vec[1]-vec[0]==vec[2]-vec[1])
				{
					cout<<"YES"<<endl;
				}
				else cout<<"NO"<<endl;
			}
			else
				cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}