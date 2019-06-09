#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const ll mod = 1000000007;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
const int maxn=100010;
int a[maxn];
map<int,int>mymap;
set<int>myset;

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,m,x,i,j;
	vector<int>vec;
	while(cin>>n>>m)
	{
		string ans="";
		mymap.clear();
		myset.clear();
		for( i = 1 ; i <= n ; i++)
			myset.insert(i);
		for( i = 0 ; i < m ; i++)
		{
			cin>>x;
			if(myset.find(x)!=myset.end())
				myset.erase(x);	
			if(myset.size()==0)
			{
				mymap[x]++;
				ans+='1';
				for( j = 1 ; j <= n ; j++)
				{
					mymap[j]--;
					if(mymap[j]==0)
						myset.insert(j);
				}
			}
			else
			{
				mymap[x]++;
				ans+='0';
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}