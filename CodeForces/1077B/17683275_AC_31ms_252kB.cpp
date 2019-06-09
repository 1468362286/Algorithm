#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;

int a[110];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i;
	while(cin>>n)
	{
		int ans=0;
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 1 ; i < n-1 ; i++)
		{
			if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
			{
				a[i+1]=0;
				ans++;
			}		
		}
		cout<<ans<<endl;
	}
	return 0;
}