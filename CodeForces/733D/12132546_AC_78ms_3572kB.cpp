#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
struct Node
{
	int a,b,c;
	int id;
	friend bool operator<(Node A,Node B)
	{
		if(A.a==B.a)
		{
			if(A.b==B.b)
				return A.c<B.c;
			else
				return A.b>B.b;
		}
		else 
			return A.a>B.a;
	}
}node[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x,y,z;
	while(~scanf("%d",&n))
	{
		int ansx=0,ansy=0;
		int maxi = 0;
		int flag = 0;
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(x<y)swap(x,y);
			if(x<z)swap(x,z);
			if(y<z)swap(y,z);
			node[i].a = x;
			node[i].b = y;
			node[i].c = z;
			node[i].id = i;
			if(maxi<z)
			{
				maxi = z;
				ansx = i;
			}
		}
		sort(node,node+n);
		/*
		for( i = 0 ; i < n; i++)
			printf("%d %d %d\n",node[i].a,node[i].b,node[i].c);
		*/	
		int l=0,r=0;
		for( i = 0 ; i < n ; i++)
		{
			if(node[i].a==node[i+1].a&&node[i].b==node[i+1].b)
			{
				r=i+1;
			}
			else
			{
				int d = node[r-1].c+node[r].c;
				int mina = 0x3f3f3f3f;
				mina = min(node[r].a,node[r].b);
				if(maxi<min(mina,d))
				{
					flag = 1;
					maxi = min(mina,d);
					ansx = node[r-1].id;
					ansy = node[r].id;
				}
			//	l=r=i;
			}
		}
		if(!flag)
			printf("1\n%d\n",ansx+1);
		else
		{
			if(ansx>ansy)swap(ansx,ansy);
			printf("2\n%d %d\n",ansx+1,ansy+1);
		}
	}
	return 0;
}
