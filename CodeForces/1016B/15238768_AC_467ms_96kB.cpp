#include <iostream>
#include <string>
using namespace std;
const int maxn = 10010;
int hay[maxn],shay[maxn];
int main()
{
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	int n,m,q,l,r,i,j;
	string s,t;
	while(cin>>n>>m>>q)
	{
		cin>>s>>t;
		s=" "+s;
		t=" "+t;
		for( i = 1 ; i <= n-m+1 ; i++)
		{
			hay[i]=1;
			for( j = 0 ; j < m ; j++)
			{
				if(s[i+j]!=t[1+j])
				{
					hay[i]=0;
					break;
				}
			}
			shay[i]=shay[i-1]+hay[i];
		}
		while(q--)
		{
			cin>>l>>r;
			r=r-m+1;
			if(r<l)
				cout<<"0"<<endl;
			else
				cout<<shay[r]-shay[l-1]<<endl;
		}
		
	}
	return 0;
}