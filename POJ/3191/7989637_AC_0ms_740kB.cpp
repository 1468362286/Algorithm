#include <iostream>
using namespace std;

int main()
{
	int i,n,k,t,sk[10000],tp;
	while(cin>>n)
	{
		tp = 0;
		while(n)
		{
			k = n % -2;
			t = n / -2;
			if(k<0)
			{
				k = k + 2;
				t++;
			}
			n = t;
			sk[++tp]=k;
		}
		for( i = tp ; i >= 1; i--)
		{
			cout<<sk[i];
		}
		if(tp==0)cout<<"0";
		cout<<endl;
	}
	return 0;
}