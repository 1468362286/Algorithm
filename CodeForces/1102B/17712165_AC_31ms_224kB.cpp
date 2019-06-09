#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 5010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int ans[maxn];
int vist[maxn];
map<int,int>mymap;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i,n,k;
	while(cin>>n>>k)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
			cin>>a[i],mymap[a[i]]++;
		map<int,int>::iterator it;
		int flag=0;
		int maxi=0;
		for( it = mymap.begin() ; it!=mymap.end() ; it++)
		{
			int x = (*it).first;
			int y = (*it).second;
			maxi=max(maxi,y);
			if(y>k)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			for( i = 0 ; i < n ; i++)
			{
				if(mymap[a[i]])
				{
					ans[i]=mymap[a[i]];
					mymap[a[i]]--;
				}
			}
			k-=maxi;
			if(k)
			{
				for( i = 0 ; i < n ; i++)
				{
					if(!vist[ans[i]])
					{
						vist[ans[i]]=1;
					}
					else
					{
						ans[i]=++maxi;
						k--;
						if(k==0)
							break;
					}
				}
			}
			for( i = 0 ; i < n ; i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}