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
const int maxn = 2010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
bool vist[maxn];
map<int,int>mymap;
struct Node
{
	int x,id;
	bool operator<(const Node A)const
	{
		return A.x<x;
	}
}node[maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,m,i,first,u,v,x;
	while(cin>>n>>m)
	{
		memset(vist,false,sizeof(vist));
		for( i = 1 ; i <= 2*n ; i++)
			cin>>node[i].x,node[i].id=i;
		vector<int>vec;
		vec.clear();
		mymap.clear();
		for( i = 0 ; i < m ; i++)
		{
			cin>>u>>v;
			mymap[u]=v;
			mymap[v]=u;
			if(node[u].x>node[v].x)
			{
				vec.push_back(u);
			}
			else
				vec.push_back(v);
		}
		sort(node+1,node+2*n+1);
		sort(vec.rbegin(),vec.rend());
		cin>>first;
		int tmp=n;
		if(first==1)
		{
			if(vec.size()!=0)
			{
				cout<<vec[0]<<endl;
				vist[vec[0]]=true;
				if(mymap.find(vec[0])!=mymap.end())
					vist[mymap[vec[0]]]=true;
			}
			else
			{
				cout<<node[1].id<<endl;
				vist[node[1].id]=true;
			}
			while(tmp--)
			{
				fflush(stdout);
				scanf("%d",&x);
				vist[x]=true;
				int pos=0;
				for( i = 0 ; i < vec.size() ; i++)
					if(!vist[vec[i]])
					{
						pos=vec[i];
						break;
					}
				if(pos!=0)
				{
					cout<<pos<<endl;
					vist[pos]=true;
					if(mymap.find(pos)!=mymap.end())
						vist[mymap[pos]]=true;
					continue;
				}
				for( i = 1 ; i <= 2*n ; i++)
				{
					if(!vist[node[i].id])
					{
						cout<<node[i].id<<endl;
						vist[node[i].id]=true;
						break;
					}
				}		
			}
		}
		else
		{
			while(tmp--)
			{
				fflush(stdout);
				scanf("%d",&x);
				vist[x]=true;
				if(mymap.find(x)!=mymap.end()&&!vist[mymap[x]])
				{
					cout<<mymap[x]<<endl;
					vist[mymap[x]]=true;
				}
				else
				{
					int pos=0;
					for( i = 0 ; i < vec.size() ; i++)
					{
						if(!vist[vec[i]])
						{
							pos=vec[i];
							break;
						}
					}
					if(pos!=0)
					{
						cout<<pos<<endl;
						vist[pos]=true;
						if(mymap.find(pos)!=mymap.end())
						vist[mymap[pos]]=true;
						continue;
					}
					for( i = 1 ; i <= 2*n ; i++)
					{
						if(!vist[node[i].id])
						{
							cout<<node[i].id<<endl;
							vist[node[i].id]=true;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}