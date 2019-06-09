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
const int maxn=200010;
typedef _int64 ll;
map<char,vector<int> >mymap1,mymap2;
int vist1[maxn],vist2[maxn];
vector<pair<int,int> >ans;
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,j;
	string s1,s2;
	while(cin>>n)
	{
		cin>>s1>>s2;
		mymap1.clear();
		mymap2.clear();
		memset(vist1,0,sizeof(vist1));
		memset(vist2,0,sizeof(vist2));
		vector<int>cnt1,cnt2;
		for( i = 0 ; i < n ; i++)
		{
			if(s1[i]=='?')
				cnt1.push_back(i+1);
			else
			{
				mymap1[s1[i]].push_back(i+1);
			}
		}
		for( i = 0 ; i < n ; i++)
		{
			if(s2[i]=='?')
				cnt2.push_back(i+1);
			else
				mymap2[s2[i]].push_back(i+1);
		}
		for( i = 0 ; i < 26 ; i++)
		{
			char tmp = 'a'+i;
			if(mymap1.find(tmp)!=mymap1.end()&&mymap1[tmp].size()>0&&mymap2.find(tmp)!=mymap2.end()&&mymap2[tmp].size()>0)
			{
				int t = min(mymap1[tmp].size(),mymap2[tmp].size());
				for( j = 0 ; j < t ; j++)
				{
					vist1[mymap1[tmp][j]]=vist2[mymap2[tmp][j]]=1;
					ans.push_back(make_pair(mymap1[tmp][j],mymap2[tmp][j]));
				}
			}
		}
		vector<int>res1,res2,Res1,Res2,Cnt1,Cnt2,vec;
		res1.clear(),res2.clear(),Res1.clear(),Res2.clear(),Cnt1.clear(),Cnt2.clear(),vec.clear();
		map<char,vector<int> >::iterator it;
		for( it = mymap1.begin();it!=mymap1.end();++it)
		{
			vec = (*it).second;
			for( i = 0 ; i < vec.size() ; i++)
				if(!vist1[vec[i]])
					res1.push_back(vec[i]);
		}
		map<char,vector<int> >::iterator It;
		for( It = mymap2.begin();It!=mymap2.end();++It)
		{
			vec = (*It).second;
			for( i = 0 ; i < vec.size() ; i++)
				if(!vist2[vec[i]])
					res2.push_back(vec[i]);
		}
		for( i = 0 ; i < min(cnt1.size(),res2.size()) ; i++)
		{
			vist1[cnt1[i]]=vist2[res2[i]]=1;
			ans.push_back(make_pair(cnt1[i],res2[i]));
		}
		for( i = 0 ; i < cnt1.size() ; i++)
			if(!vist1[cnt1[i]])
				Cnt1.push_back(cnt1[i]);
		for( i = 0 ; i < res2.size() ; i++)
			if(!vist2[res2[i]])
				Res2.push_back(res2[i]);
		for( i = 0 ; i < min(cnt2.size(),res1.size()) ; i++)
		{
			vist2[cnt2[i]]=vist1[res1[i]]=1;
			ans.push_back(make_pair(res1[i],cnt2[i]));
		}
		for( i = 0 ; i < cnt2.size() ; i++)
			if(!vist2[cnt2[i]])
				Cnt2.push_back(cnt2[i]);
		for( i = 0 ; i < res1.size() ; i++)
			if(!vist1[res1[i]])
				Res1.push_back(res1[i]);
		for( i = 0 ; i < min(Cnt1.size(),Cnt2.size()) ; i++)
		{
			ans.push_back(make_pair(Cnt1[i],Cnt2[i]));
		}
		cout<<ans.size()<<endl;
		for( i = 0 ; i < ans.size() ; i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}