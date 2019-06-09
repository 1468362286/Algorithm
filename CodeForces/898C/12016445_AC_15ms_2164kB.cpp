#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;

map<string,set<string> > mymap;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,k,i,j,flag;
	string s,ch;
	while(~scanf("%d",&n))
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>s>>k;
			for( j = 0 ; j < k ; j++)
			{
				cin>>ch;
				flag = 0;
				set<string> Tmp = mymap[s];
				set<string>::iterator pp;
				string tmp;
				for( pp =Tmp.begin() ; pp != Tmp.end() ; pp++)
				{
					tmp = *pp;
				//	int len = ch.size();
					if(tmp.size()>=ch.size())
					{
						if(tmp.substr(tmp.size()-ch.size(),tmp.size())==ch)
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
				if(flag==0)
				{
					mymap[s].insert(ch);
				}
				else if(flag==2)
				{
					mymap[s].erase(tmp);
					mymap[s].insert(ch);
				}
			}
		}
		map<string,set<string> >::iterator it;
		cout<<mymap.size()<<endl;
		for(it=mymap.begin(); it!=mymap.end() ; it++)
		{
			string tmp = it->first;
			set<string> tp = it->second;
			cout<<tmp<<" "<<tp.size();
			
			set<string>::iterator st;
			for( st = tp.begin() ; st != tp.end() ; st++)
			{
				cout<<" "<<*st;
			}			
			cout<<endl;
		}
	}
	return 0;
}

/*耗时：15ms*/