#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

map<string,set<string> > mymap;
set<string> myset;
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,j,o,flag;
	string s,ch;
	while(~scanf("%d",&n))
	{

		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
		//	myset.clear();
			cin>>s>>k;
			for( j = 0 ; j < k ; j++)
			{
				cin>>ch;
				if(ch=="22"&&s=="e")
				{
					int gg = 1;
				}
				//if(mymap[s].find(ch)==myset.end())
				//{
				//	map<string,vector<string> >::iterator it;
					flag = 0;
					//for( it = mymap[s].begin() ; it != mymap[s].end() ; it++)
				//	map<string,set<string> >::iterator it;
				//	it=mymap[s];
				//	set<string> Tmp = it->second;
					set<string> Tmp = mymap[s];
					set<string>::iterator pp;
					string tmp;
					for( pp =Tmp.begin() ; pp != Tmp.end() ; pp++)
					{
						//string tmp = mymap[s];
						tmp = *pp;
						int len = ch.size();
						if(tmp.size()>=len)
						{
							if(tmp.substr(tmp.size()-len,tmp.size())==ch)
							{
								flag = 1;
								break;
							}
						}
						else
						{
							if(ch.substr(ch.size()-tmp.size(),ch.size())==tmp)
							{
								flag = 2;
								break;
							}
						}
					}
					if(!flag)
					{
						mymap[s].insert(ch);
					//	myset.insert(ch);
					}
					else if(flag==2)
					{
						mymap[s].erase(tmp);
						mymap[s].insert(ch);
					}
				//}
			}
		}
		map<string,set<string> >::iterator it;
		cout<<mymap.size()<<endl;
		for(it=mymap.begin(); it!=mymap.end() ; it++)
		{
			string tmp = it->first;
			set<string> tp;
			tp.clear();
			tp = it->second;
			cout<<tmp<<" "<<tp.size();
			
			set<string>::iterator st;
			for( st = tp.begin() ; st != tp.end() ; st++)
			{
		//		string gg = *st;
				cout<<" "<<*st;
			}
			
			cout<<endl;
		}
	}
	return 0;
}