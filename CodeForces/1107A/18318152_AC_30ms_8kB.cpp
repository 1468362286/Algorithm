#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int q,n;
	string s;
	cin>>q;
	while(q--)
	{
		cin>>n;
		cin>>s;
		if(n==2&&s[0]>=s[1])
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl<<"2"<<endl;
			cout<<s[0]<<" ";
			for(int i = 1 ; i < n ; i++)
				cout<<s[i];
			cout<<endl;
		}
	}
	return 0;
}