#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef _int64 ll;
const int maxn = 100010;
ll sum[maxn];
map<ll,ll> m;
vector<ll> kn;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j,t;
	while(cin>>n>>k)
	{
		ll tt=1;
		while(1)
		{
			kn.push_back(tt);
			if(k==1||(k==-1&&tt==-1)||tt>(10e14/abs(k))||tt<(-10e14/abs(k))) break;
			tt*=k;
		}
		ll re=0;
		for( i = 0 ; i < kn.size() ; i++)
			m[kn[i]]++;
		for( i = 1 ; i <= n ; i++)
		{
			cin>>t;
			sum[i]=sum[i-1]+t;
			if(m.find(sum[i])!=m.end())
				re+=m[sum[i]];
			for( j = 0 ; j < kn.size() ; j++)
				m[sum[i]+kn[j]]++;
		}
		printf("%I64d\n",re);
	}
	return 0;
}