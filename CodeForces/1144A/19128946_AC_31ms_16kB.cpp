#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn=1010;
const int inf = 0x7fffffff;
typedef _int64 ll;
map<char,int>mymap;

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		mymap.clear();
		for( i = 0 ; i < s.size() ; i++)
		{
			mymap[s[i]]++;
		}
		map<char,int>::iterator it;
		char c;
		int flag=0;
		for( it = mymap.begin() ; it!=mymap.end() ; ++it)
		{
			if((*it).second!=1)
			{
				flag=1;
				break;
			}
			if(it==mymap.begin())
			{
				c=(*it).first;
				continue;
			}
			if((*it).first==c+1)
			{
				c=(*it).first;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}	