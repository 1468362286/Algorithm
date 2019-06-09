#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef _int64 ll;
map<ll,int>mymap;
int main()
{
	//freopen("in.txt","r",stdin);
	ll n,k;
	while(~scanf("%I64d%I64d",&n,&k))
	{
		int flag=0;
		for(ll i = 1 ; i <= k ; i++)
		{
			if(mymap[n%i]==0)
				mymap[n%i]++;
			else
			{
				flag=1;
				break;
			}
		}
		if(!flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}