#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
//	freopen("in.txt","r",stdin);
    ll t,n,m,i,flag;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n>m)swap(n,m);
		flag=1;
		while(m%n&&m/n==1)
		{
			flag^=1;
			m%=n;
			swap(n,m);
		}
		if(flag)cout<<"Ari"<<endl;
		else cout<<"Rich"<<endl;
	}
	return 0;
}