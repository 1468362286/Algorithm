#include <iostream>
#include <string>
#include <map>
using namespace std;
char a[100];
map<char,int> mymap;
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int i;
	while(cin>>s)
	{
		mymap.clear();
		int cnt=0;
		int flag=0;
		if(s[0]=='a')
		{
			a[cnt++]='a';
			mymap['a']++;
		}
		else
		{
			printf("NO\n");
			continue;
		}
		for( i = 1 ; i < s.size() ; i++)
		{
			if(s[i]!=s[i-1])
			{
				a[cnt++]=s[i];
			}
			if(cnt==4)
			{
				flag=1;
				break;
			}
			mymap[s[i]]++;
		}
		if(a[0]=='a'&&a[1]=='b'&&a[2]=='c')
		{
			if((mymap['c']==mymap['a']||mymap['c']==mymap['b'])&&!flag)
			{
				printf("YES\n");
			}
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}