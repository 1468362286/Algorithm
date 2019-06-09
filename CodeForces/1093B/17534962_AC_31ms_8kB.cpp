#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int h[100];
int main()
{
	//freopen("in.txt","r",stdin);
	int t,i,j;
	string s;
	cin>>t;
	while(t--)
	{
		memset(h,0,sizeof(h));
		cin>>s;
		int cnt=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			h[s[i]-'a']++;
			if(s[i]==s[s.size()-1-i])
			{
				cnt++;
			}
		}
		int cn=0;
		for( i = 0 ; i < 26 ; i++)
			if(h[i])cn++;
		if(cn==1)
			cout<<"-1"<<endl;
		else
		{
			char x;
			for( i = 0 ; i < 26 ; i++)
				if(h[i])
					for( j = 0 ; j < h[i] ; j++)
						x='a'+i,printf("%c",x);
			printf("\n");
		}
	}
	return 0;
}