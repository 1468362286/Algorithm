#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
#include <numeric>
using namespace std;
const int maxn = 510;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;
#define x first
#define y second
char ch[6]="aeiou";
bool judge(char c)
{
	for(int i = 0 ; i < 5 ; i++)
		if(c==ch[i])
			return true;
	return false;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	string s1,s2;
	cin>>s1>>s2;
	int flag=0;
	if(s1.size()!=s2.size())
	{
		cout<<"No"<<endl;
		return 0;
	}
	for(int i = 0 ; i < min(s1.size(),s2.size()) ; i++)
	{
		if((judge(s1[i])&&!judge(s2[i]))||(judge(s2[i])&&!judge(s1[i])))
		{
			flag=1;
			break;
		}
	}
	if(flag)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}