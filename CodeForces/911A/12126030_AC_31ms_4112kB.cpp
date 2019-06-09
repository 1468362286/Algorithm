#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Node
{
	int x;
	int id;
	Node()
	{
		x = 0;
		id = 0;
	}
	friend bool operator < (Node A,Node B)
	{
		return A.x<B.x;
	}
}node[maxn];
int min(int a,int b){return a>b?b:a;}
vector<int> b;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",&x);
			node[i].x = x;
			node[i].id = i;
		}
		sort(node,node+n);
		b.clear();
		b.push_back(node[0].id);
		int flag = 0;
		for( i = 1 ; i < n ; i++)
		{
			if(node[i].x==node[0].x)
			{
				b.push_back(node[i].id);
				flag = 1;
			}
			else if(!flag)
			{
				b.push_back(node[i].id);
				break;
			}
			else if(flag)
				break;
		}
		sort(b.begin(),b.end());
		int mina = 0x3f3f3f3f;
		for( i = 1 ; i < b.size();  i++)
		{
			mina = min(b[i]-b[i-1],mina);
		}
		printf("%d\n",mina);
	}
	return 0;
}