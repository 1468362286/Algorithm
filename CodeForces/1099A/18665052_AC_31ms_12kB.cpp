#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;
const int maxn=300010;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int w,h,u1,d1,u2,d2;
	while(cin>>w>>h>>u1>>d1>>u2>>d2)
	{
		int ans=w;
		for(int i = h ; i >= 0 ; i--)
		{
			ans+=i;
			if(i==d1)
			{
				ans-=u1;
				if(ans<0)ans=0;
			}
			else if(i==d2)
			{
				ans-=u2;
				if(ans<0)ans=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}