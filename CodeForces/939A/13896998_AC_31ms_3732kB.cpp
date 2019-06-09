#include <iostream>
#include <string>
#include <set>
using namespace std;
int a[5010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,x;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		int flag=0;
		for( i = 1 ; i <= n ; i++)
		{
			if(a[a[a[i]]]==i)
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}