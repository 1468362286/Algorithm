#include <iostream>
#include <string>
#include <vector>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,x,y;
	while(cin>>n)
	{
		int flag=0;
		int pre=INT_MAX;
		for( i = 0 ; i < n ; i++)
		{
			cin>>x>>y;
			if(!flag)
			{
				int tmp = max(x,y);
				if(x<=pre&&y<=pre)
				{
					pre = tmp;
				}
				else if(x<=pre&&y>pre)
				{
					pre=x;
				}
				else if(x>pre&&y<=pre)
				{
					pre=y;
				}
				else
				{
					flag=1;
				}
			}
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}