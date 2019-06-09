#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 200005;
vector<int> vec[maxn];
int max(int a,int b){return a>b?a:b;}

int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int i,j;
	while(cin>>s)
	{
		int cnt=0;
		int zero=0;
		int Max=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='0')
			{
				vec[++zero].push_back(i);
			}
			else
			{
				if(zero==0)
					return puts("-1"),0;
				vec[zero--].push_back(i);
			}
			Max=max(Max,zero);
		}
		if(Max!=zero)
			return puts("-1"),0;
		printf("%d\n",Max);
		for( i = 1 ; i <= Max ; i++)
		{
			printf("%d ",vec[i].size());
			for( j = 0 ; j < vec[i].size() ; j++)
				printf("%d%s",vec[i][j]+1,j==vec[i].size()-1?"\n":" ");
		}
	}
	return 0;
}