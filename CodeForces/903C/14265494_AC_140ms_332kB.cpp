#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int a[5010];
multiset<int> myset;
set<int> m;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i],myset.insert(a[i]),m.insert(a[i]);
		int ans=0;
	//	cout<<myset.size()<<endl;
		while(myset.size()>0)
		{
			ans++;
			set<int>::iterator it;
			for( it = m.begin(); it!=m.end() ; it++)
			{
				multiset<int>::iterator pos = myset.find((*it));
				myset.erase(pos);
			}
			m.clear();
			multiset<int>::iterator its;
			for( its = myset.begin() ; its != myset.end() ; its++)
			{
				m.insert((*its));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}