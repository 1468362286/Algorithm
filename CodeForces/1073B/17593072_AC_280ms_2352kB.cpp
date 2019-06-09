#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;

const int maxn = 200010;
int n,a[maxn],b[maxn],vist[maxn];
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		for( i = 0 ; i < n ; i++)
			cin>>b[i];
		int s=0;
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
		{
			if(!vist[b[i]])
			{
				for( j = s ; j < n ; j++)
				{
					vist[a[j]]=1;
					if(b[i]==a[j])
					{
						cout<<j-s+1<<" ";
						s=j+1;
						break;
					}
				}
			}
			else cout<<"0"<<" ";
		}
		cout<<endl;
	}
	return 0;
}