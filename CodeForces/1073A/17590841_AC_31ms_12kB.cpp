#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;

int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	string s;
	while(cin>>n)
	{
		cin>>s;
		if(n==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1 ; i < s.size() ; i++)
		{
			if(s[i]!=s[i-1])
			{
				cout<<"YES"<<endl;
				cout<<s[i-1]<<s[i]<<endl;
				exit(0);
			}
		}
		cout<<"NO"<<endl;
	}
	return 0;
}