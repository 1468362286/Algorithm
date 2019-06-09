#include <iostream>
#include <string>
using namespace std;
const int maxn = 200010;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}
		int ans=0;
		for( i = 0 ; i < n ; )
		{
			for( j = i+1 ; j < n ; j++)
			{
				if(a[j]>2*a[j-1])
				{	
					break;
				}
			}
			ans=max(ans,(j-i));
			i=j;
		}	
		cout<<ans<<endl;
	}
	return 0;
}


