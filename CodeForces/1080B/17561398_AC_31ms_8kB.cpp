#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef _int64 ll;

int main()
{
	//freopen("in.txt","r",stdin);
	int q,l,r,x,ans;
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		if(l%2==0)x=-1;
		else x=1;
		if((r-l+1)%2==0)ans=(r-l+1)/2*x;
		else ans=(r-l+1)/2*x+(r%2==0?1:-1)*r;
		cout<<ans<<endl;
	}
	return 0;
}