#include <iostream>
#include <string>
using namespace std;
const int inf = 1000000000;
const int maxn = 100010;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,l,r,i,j;
	string s;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		cin>>s;
		l=-inf,r=inf;
		for( i = 4 ; i < n ; i++)
		{
			if(s[i]=='1')
			{
				int maxi=-inf;
				for( j = i ; j >=i-4 ; j--)
				{
					maxi=max(maxi,a[j]);
				}
				int cnt=0;
				for( j = i ; j >= i-4 ; j--)
				{
					if(s[j]=='0')
						cnt++;
				}
				if(cnt==4)
				{
					l = max(l,maxi+1);
				}
			}
			else if(s[i]=='0')
			{
				int mina=inf;
				for( j = i ; j >= i-4 ; j--)
				{
					mina = min(mina,a[j]);
				}
				int cnt=0;
				for( j = i ; j >= i-4 ; j--)
				{
					if(s[j]=='1')
						cnt++;
				}
				if(cnt==4)
				{
					r = min(r,mina-1);
				}
			}
		}
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}