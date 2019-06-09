#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef _int64 ll;
const int N = 200010;
set<ll> st;

ll n,m,cnt[N],arr[N],res,val,ans;

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		for( i = 0 ; i < m ; cnt[i++]=n/m)
		{
			st.insert(ll(i));
		}
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d",&arr[i]);
			res=arr[i]%m;
	//		printf("%I64d\n",*st.rbegin());
			if(res>*st.rbegin())
				val=*st.begin();
			else
				val=*st.lower_bound(res);
			ans+=(val-res+m)%m;
			if(!--cnt[val])
				st.erase(val);
			arr[i]+=(val-res+m)%m;
		}
		printf("%I64d\n",ans);
		for( i = 0 ; i < n ; i++)
			printf("%I64d ",arr[i]);
		printf("\n");
	}
}


