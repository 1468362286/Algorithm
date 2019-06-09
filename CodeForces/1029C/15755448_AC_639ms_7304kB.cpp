#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 300010;
const int inf = 0x3f3f3f3f;
int max(int a,int b){return a>b?a:b;}
struct Node
{
	int l,r;
	int id;
}node[maxn],p[maxn];

bool cmp1(Node A,Node B)
{
	return A.l>B.l;	
}

bool cmp2(Node A,Node B)
{
	return A.r<B.r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int n,l,r,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>l>>r;
			node[i].l=l;
			node[i].r=r;
			node[i].id=i;
			p[i].l=l;
			p[i].r=r;
			p[i].id=i;
		}
		sort(node,node+n,cmp1);
		int lid1 = node[0].id;
		int lid2 = node[1].id;
		sort(node,node+n,cmp2);
		int rid1 = node[0].id;
		int rid2 = node[1].id;
		if(lid1==rid1)
		{
			if(p[rid2].r-p[lid2].l<0)
				cout<<0<<endl;
			else
				cout<<p[rid2].r-p[lid2].l<<endl;
		}
		else
		{
			int tmp1 = p[rid1].r-p[lid2].l;
			int tmp2 = p[rid2].r-p[lid1].l;
			if(max(tmp1,tmp2)<0)
				cout<<"0"<<endl;
			else
				cout<<max(tmp1,tmp2)<<endl;
		}
	}
	return 0;
}