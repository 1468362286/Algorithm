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
const int maxn = 110;
const int inf = 0x7fffffff;
typedef _int64 ll;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
map<int,int>mymap;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i;
	while(cin>>n)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			mymap[a[i]]++;
		}
		if(mymap.size()>3)
		{
			cout<<-1<<endl;
			continue;
		}
		if(mymap.size()==3)
		{
			int cnt=1;
			int A,B,C;
			map<int,int>::iterator it;
			for( it = mymap.begin() ; it!=mymap.end() ; ++it)
			{
				if(cnt==1)
					A=(*it).first;
				else if(cnt==2)
					B=(*it).first;
				else
					C=(*it).first;
				cnt++;
			}
			if(A+C==2*B)
			{
				cout<<B-A<<endl;
			}
			else
				cout<<-1<<endl;
		}
		else if(mymap.size()==2)
		{
			int tmp=(*(mymap.rbegin())).first-(*mymap.begin()).first;
			if(tmp&1)
				cout<<tmp<<endl;
			else
				cout<<tmp/2<<endl;
		}
		else
			cout<<0<<endl;
	}
	return 0;
}		