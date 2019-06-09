#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 1010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,k,i,j;
	string s;
	while(cin>>n>>k)
	{
		cin>>s;
		int maxi=0;
		for( i = 0 ; i < 26 ; i++)
		{
			char c = 'a'+i;
			int ans=0;
			for( j = 0 ; j < n ; )
			{
				int cnt=0;
				if(c==s[j])
				{
					while(s[j]==c)
					{
						cnt++;
						j++;
					}
					ans+=cnt/k;
				}
				else j++;
			}
			maxi=max(ans,maxi);
		}
		cout<<maxi<<endl;
	}
    return 0;
}