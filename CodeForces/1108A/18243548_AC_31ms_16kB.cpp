#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn = 100010;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int q,ans,l1,l2,r1,r2;
	cin>>q;
	while(q--)
	{
		cin>>l1>>r1>>l2>>r2;
		for(int i = l2 ; i <= r2 ; i++)
			if(i!=l1)
			{
				ans=i;
				break;
			}
		cout<<l1<<" "<<ans<<endl;
	}
	return 0;
}