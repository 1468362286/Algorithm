#include <iostream>
#include <algorithm>
using namespace std;
#define min(a,b) (a>b?b:a)
const int maxn=1e5+10;
int a[maxn],b[maxn];
int n,p,q;

double f(double x)
{
	double y = 1;
	for(int i = 0 ; i < n ;i++)
		y=min(y,(1.0-x*b[i])/a[i]);
	return y*p+x*q;
}
int main()
{
	int i;
	cin>>n>>p>>q;
	for( i = 0 ; i < n ; i++)
		cin>>a[i]>>b[i];
	double l = 0,r=1./(*max_element(b,b+n));
	for( i = 0 ; i < 50 ; i++)
	{
		double ll = (l+r)*0.5,rr=(ll+r)*0.5;
		if(f(ll)>f(rr)) r = rr;
		else l = ll;
	}
	printf("%.10f\n",f((l+r)*0.5));
	return 0;
}