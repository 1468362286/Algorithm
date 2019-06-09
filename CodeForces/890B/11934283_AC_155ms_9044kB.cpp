#include <stdio.h>
#include <set>
using namespace std;
const int maxn = 200010;
int a[maxn];
set<int> myset;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		int ans = 0;
		myset.clear();
		for( i = 0 ; i < n ; i++)
		{
			scanf("%d",a+i);
			myset.insert(a[i]);
		}
		for( i = n-1 ; i >= 0 ; i--)
		{
			if(myset.size()==1)
			{
				ans = *myset.begin();
				break;
			}
			myset.erase(a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}