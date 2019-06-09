#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,l;
	string s,t;
	while(cin>>n>>m)
	{
		cin>>s>>t;
		if(n-1>m)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int flag=0;
		for( i = 0,l=0 ; i < m ; i++,l++)
		{
			if(s[l]=='*')
			{
				i+=(m-n);
			}
			else if(s[l]!=t[i])
			{
				flag=1;
				break;
			}
		}
		if(s.find('*')==string::npos&&n!=m)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}