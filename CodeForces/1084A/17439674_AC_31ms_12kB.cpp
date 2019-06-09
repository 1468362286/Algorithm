#include <iostream>
#include <string>
using namespace std;
const int inf=0x3f3f3f3f;
int a[110];
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		int mina=inf;
		for( i = 1 ; i <= n ; i++)
		{
			int ans=0;
			for( j = 1 ; j <= n ; j++)
			{
				ans+=(abs(j-i)+j-1+i-1)*2*a[j];
			}
			mina=min(ans,mina);
		}
		cout<<mina<<endl;
	}
	return 0;
}