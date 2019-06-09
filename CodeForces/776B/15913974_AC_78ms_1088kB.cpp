#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
int prime[maxn];
int ans[maxn];
void init()
{
	memset(prime,0,sizeof(prime));
	for(int i = 2 ; i < maxn ; i++)
		if(!prime[i])
		for(int j = 2*i ; j < maxn ; j+=i)
		{
			prime[j]=1;
		}
}
int main()
{
	//freopen("in.txt","r",stdin);
	init();
	int n,i;
	while(cin>>n)
	{
		if(n==1)
		{
			cout<<"1"<<endl<<"1"<<endl;
			continue;
		}
		int cnt=1;
		for( i = 2 ; i <= n+1 ; i++)
		{
			if(!prime[i])
			{
				ans[i]=1;
			}
			else
			{
				ans[i]=2;
			}
		}
		if(n>=3)
		cout<<"2"<<endl;
		else cout<<"1"<<endl;
		for( i = 2 ; i <= n+1 ; i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}