#include <iostream>
#include <string>
#include <math.h>
using namespace std;
const double pi=acos(-1.0);
const double eps = -1e-10;
int main()
{
	//freopen("in.txt","r",stdin);
	double r,R;
	int n;
	while(cin>>n>>R>>r)
	{
		if(R<r)
		{
			puts("NO");
			continue;
		}
		if(2*r>R)
		{
			if(n==1)
				puts("YES");
			else
				puts("NO");
			continue;
		}
		double deltaBCD = 2*asin(r/(R-r));
		if(2*pi-deltaBCD*n>eps)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}