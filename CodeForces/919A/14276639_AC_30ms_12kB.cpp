#include <iostream>
#include <string>
using namespace std;
const double inf=0x3f3f3f3f;
double min(double a,double b){return a>b?b:a;}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,m;
	while(cin>>n>>m)
	{
		double a,b;
		double ans=inf;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>a>>b;
			ans=min(ans,a/b);
		}
		printf("%.8lf\n",ans*m);
	}
	return 0;
}