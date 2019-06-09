#include <iostream>
#include <string>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1010;
int a[maxn];
int pre_sum[maxn];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,w,i;
	while(cin>>n>>w)
	{
		int maxi = -inf;
		int mina = inf;
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
			pre_sum[i]=pre_sum[i-1]+a[i];
			maxi = max(maxi,pre_sum[i]);
			mina = min(mina,pre_sum[i]);
		}
		int r = w-maxi;
		int l = -mina;
		if(l>w||r<0||r<l)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(l<0)l=0;
		if(r>w)r=w;
		cout<<r-l+1<<endl;
	}
	return 0;	
}