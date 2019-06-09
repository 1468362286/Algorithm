#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef _int64 ll;
ll min(ll a,ll b){return a>b?b:a;}
int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	ll n,k,s;
	while(~scanf("%I64d%I64d%I64d",&n,&k,&s))
	{
		if((n-1)*k<s||k>s)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		vector<ll>ans;
		ans.clear();
		ll sourse=1;
		while(k--)
		{
			ll tmp = min(s-k,n-1);
			if(sourse+tmp<=n)
				sourse+=tmp;
			else
				sourse-=tmp;
			s-=tmp;
			ans.push_back(sourse);
		}
		for( i = 0 ; i < ans.size() ; i++)
			printf("%I64d ",ans[i]);
		printf("\n");
	}
	return 0;
}