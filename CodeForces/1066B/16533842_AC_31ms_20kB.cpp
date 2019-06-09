#include <iostream>
#include <string>
#include <vector>
using namespace std;
int a[1010];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int i,n,r;
	while(cin>>n>>r)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
		}
		int last=0,num=0;
		bool flag;
		int pos;
		while(last<n)
		{
			flag=false;
			int pp=max(last-r+1,0);
			for( i = n ; i > pp ; i--)
			{
				if(a[i])
				{
					if(i-r<=last)
					{
						pos=i;
						flag=true;
						break;
					}
				}
			}
			if(!flag)
			{
				cout<<"-1"<<endl;
				return 0;
			}
			last=pos+r-1;
			num++;
		}
		cout<<num<<endl;
	}
	return 0;
}