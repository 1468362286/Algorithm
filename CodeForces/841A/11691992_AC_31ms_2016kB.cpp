#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int hash1[300];
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int n,m;
	while(cin>>n>>m)
	{
		cin>>s;
		memset(hash1,0,sizeof(hash1));
		int max = 0;
		for(int i = 0 ; i < n ; i++)
		{
			hash1[s[i]]++;
			if(hash1[s[i]]>max)
				max = hash1[s[i]];
		}
		if(max>m)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}