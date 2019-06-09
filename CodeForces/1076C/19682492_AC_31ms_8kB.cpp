#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 100010;
typedef _int64 ll;


int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t;
	double d;
	cin>>t;
	while(t--)
	{
		cin>>d;
		double tmp = d*d-4*d;
		if(tmp>=0)
		{
			double a = (sqrt(double(tmp))+d)/2;
			double b = d-a;
			printf("Y %.9lf %.9lf\n",a,b);
		}
		else
			cout<<"N"<<endl;
	}
	return 0;
}