#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	string s;
	while(cin>>s)
	{
		int ans = 0;
		int len = s.size();
		for(int i = 0 ; i < len ; i++ )
		{
			if(s[i]=='Q')
			{
				for(int j = i+1 ; j < len ; j++)
				{
					if(s[j]=='A')
					{
						for(int k = j+1 ; k < len ; k++)
						{
							if(s[k]=='Q')
								ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}