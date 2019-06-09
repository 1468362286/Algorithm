#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	while(cin>>n>>k)
	{
		int ans=inf;
		for(int i = 1 ; i < k ; i++)
		{
			if(n%i==0)
			{
				int tmp=n/i;
				ans=min(ans,tmp*k+i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}