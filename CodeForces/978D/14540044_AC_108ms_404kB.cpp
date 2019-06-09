#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const int maxn =100010;
const int inf = 0x3f3f3f3f;
int a[maxn];
int dir[3]={1,-1,0};
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
		}
		if(n<=2)
		{
			cout<<"0"<<endl;
			continue;
		}
		int mina = inf;
		for( i = 0 ; i < 3 ; i++)
		{
			for( j = 0 ; j < 3 ; j++)
			{
				int x1 = a[0]+dir[i];
				int x2 = a[1]+dir[j];
				int d = x2-x1;
				int flag=0;
				int ans = abs(dir[i])+abs(dir[j]);		
				int y;
				int pre=x2;
				for( k = 2 ; k < n ; k++)
				{
					y = a[k]-(pre+d);
					if(y<-1||y>1)
					{
						flag=1;
						break;
					}
					else if(y==-1||y==1)
					{
						ans++;
					}
					pre+=d;
				}
				if(!flag)
					mina=min(ans,mina);
			}
		}
		if(mina==inf)
			cout<<"-1"<<endl;
		else
			cout<<mina<<endl;
	}
	return 0;
}