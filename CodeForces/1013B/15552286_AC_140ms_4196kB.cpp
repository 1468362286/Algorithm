#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 100010;
int a[maxn];
map<int,int>mymap,kk;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i;
	while(cin>>n>>k)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
			cin>>a[i],mymap[a[i]]++;
		map<int,int>::iterator it;
		int flag=0;
		for( it = mymap.begin() ; it!=mymap.end() ; it++)
		{
			int x = (*it).second;
			if(x>=2)
			{
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"0"<<endl;
			continue;
		}
		kk.clear();
		for( i = 0 ; i < n ; i++)
		{
			int tmp = a[i]&k;
			if(tmp!=a[i]&&mymap.find(tmp)!=mymap.end())
			{
				flag=1;
				break;
			}
			kk[tmp]++;
		}
		for( it = kk.begin() ; it!=kk.end() ; it++)
		{
			if((*it).second>=2)
			{
				if(flag==0)
					flag=2;
			}
		}
		if(flag==1)cout<<"1"<<endl;
		else if(flag==2)cout<<"2"<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}