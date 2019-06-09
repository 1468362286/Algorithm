#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 100010;
int vist[maxn];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
struct Node
{
	int l,r;
	int cn;
	bool operator<(const Node &other)const
	{
		if(l!=other.l)return l<other.l;
		if(r!=other.r)return r<other.r;
		return true;
	}
}node[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int T,n,i;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for( i = 0 ; i < n ; i++)
		{
			cin>>node[i].l>>node[i].r;
			node[i].cn=i;
		}
		sort(node,node+n);
		memset(vist,0,sizeof(vist));
		int flag=0;
		int L = node[0].l,R=node[0].r;
		vist[node[0].cn]=1;
		for( i = 1 ; i < n ; i++)
		{
			if(R>=node[i].l)
			{
				vist[node[i].cn]=1;
				L=min(L,node[i].l);
				R=max(R,node[i].r);
			}
			else
			{
				vist[node[i].cn]=2;
				flag=1;
			}
		}
		if(flag)
		{
			for( i = 0 ; i < n ; i++)
				if(vist[i]==1)
					cout<<"1 ";
				else
					cout<<"2 ";
			cout<<endl;
		}
		else cout<<"-1"<<endl;
	}
	return 0;
}