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
struct Node
{
	int x,y;
}node[maxn];
struct Pos
{
	int a,b;
}pos[maxn];
int vist[maxn];

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,i,j,k;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>node[i].x>>node[i].y;
		}
		for( i = 0 ; i < n ; i++)
		{
			cin>>pos[i].a>>pos[i].b;
		}
		int gg=0;
		for( i = 0 ; i < n ; i++)
		{
			int x = node[0].x+pos[i].a;
			int y = node[0].y+pos[i].b;
			memset(vist,0,sizeof(vist));
			int gg=0;
			for( j = 1 ; j < n ; j++)
			{
				int fa=x-node[j].x;
				int fb=y-node[j].y;
				int flag=0;
				for( k = 0 ; k < n ; k++)
				{
					if(!vist[k])
					{
						if(fa==pos[k].a&&fb==pos[k].b)
						{
							flag=1;
							vist[k]=1;
							break;
						}
					}
				}
				if(!flag)
				{
					gg=1;
					break;
				}
			}
			if(!gg)
			{
				cout<<x<<" "<<y<<endl;
				break;
			}
		}
	}
    return 0;
}