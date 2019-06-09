#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn=200010;
int n,a[maxn];
map<int,int>m;

int main()
{
	//freopen("in.txt","r",stdin);
	ios::sync_with_stdio(false);
	int i;
	while(cin>>n)
	{
		m.clear();
		int len=-1,ans=-1,id;
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			int x=a[i];
			m[x]=m[x-1]+1;
			if(len<m[x])
				len=m[x],ans=x;
		}
		int r=ans,l=ans-len+1;
		cout<<len<<endl;
		for( i = 0 ; i < n ; i++)
		{
			if(a[i]==l)
			{
				cout<<i+1<<" ";
				l++;
			}
		}
		cout<<endl;
	}
	return 0;
}