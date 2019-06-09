#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,string> mymap;
map<string,int> vist;
char ch1[6][10]={"Power","Time","Space","Soul","Reality","Mind"};
char ch[6][10]={"purple","green","blue","orange","red","yellow"};

void init()
{
	int i,j;
	vist.clear();
	mymap.clear();
	for( i = 0 ; i < 6 ; i++)
	{
		string s="";
		int len = strlen(ch[i]);
		for( j = 0 ; j < len ; j++)
		{
			s+=ch[i][j];
		}
		string ss="";
		len = strlen(ch1[i]);
		for( j = 0 ; j < len ; j++)
			ss+=ch1[i][j];
		mymap[s]=ss;
		vist[s]=1;
	}
	/*
	map<string,string>::iterator it;
	for(it=mymap.begin();it!=mymap.end();it++)
		cout<<(*it).first<<" "<<(*it).second<<endl;
		*/
}
int main()
{
	//freopen("in.txt","r",stdin);
	init();
	int n,i;
	
	while(cin>>n)
	{
		string s;
		for( i = 0 ; i < n ; i++)
		{
			cin>>s;	
			vist[s]=0;
		}
		cout<<6-n<<endl;
		map<string,string>::iterator it;
		for( it = mymap.begin() ; it!=mymap.end() ; it++)
		{
			if(vist[(*it).first]==1)
			{
				cout<<(*it).second<<endl;
			}
		}
	}	
	return 0;
}