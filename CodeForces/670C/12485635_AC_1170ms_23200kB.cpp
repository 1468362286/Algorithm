#include <iostream>
#include <algorithm>
#include <map>	
#include <string>
using namespace std;
const int maxn = 200010;
map<int,int> mymap;
struct Node
{
	int b,c;
	int id;
}node[maxn];

bool cmp(Node A,Node B)
{
	if(mymap[A.b]==mymap[B.b])
		return mymap[A.c]>mymap[B.c];
	return mymap[A.b]>mymap[B.b]; 
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,x,y;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			mymap[x]++;
		}
		cin>>m;
		for( i = 0 ; i < m ; i++)
		{
			cin>>x;
			node[i].b=x;
			node[i].id=i;
		}
		for( i = 0 ; i < m ; i++)
		{
			cin>>y;
			node[i].c=y;
		}
		sort(node,node+m,cmp);
		/*
		for( i = 0 ; i < m ; i++)
			printf("%d %d\n",node[i].b,node[i].c);
			*/
		printf("%d\n",node[0].id+1);
	}
	return 0;
}