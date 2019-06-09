#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef _int64 ll;
const int maxn =100010;
int a[maxn];
int vist[maxn];
vector<int> vec;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			a[i]=-1,vist[i]=0;
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= n ; i++)
		{
			if(!vist[i])
			{
				int cnt=0;
				int flag=0;
				for( j = a[i] ; j != -1 ; j=a[j])
				{
					cnt++;
					if(j==i)
					{
						flag=1;
						break;
					}
				}
				if(flag)vec.push_back(cnt);
				if(flag)
				{
					for( j = a[i] ; j != -1 ; j=a[j])
					{
						vist[j]=1;
						if(j==i)
							break;
					}
				}
			}
		}
		sort(vec.begin(),vec.end());
		int len = vec.size();
		ll ans=0;
		for( i = 0 ; i < len ; i++)
			ans+=ll(vec[i])*ll(vec[i]);
		if(len>=2)
	//	cout<<2*(vec[len-1]*vec[len-2])+ans<<endl;
			printf("%I64d\n",2*ll(vec[len-1])*ll(vec[len-2])+ans);
		else
		//	cout<<ans<<endl;
			printf("%I64d\n",ans);
	}
	return 0;
}
