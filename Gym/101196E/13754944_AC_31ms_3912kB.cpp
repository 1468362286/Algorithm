#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> mymap;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main()
{
    //freopen("in.txt","r",stdin);
    string s;
    int i,j;
    while(cin>>s)
    {
        mymap.clear();
        for( i = 0 ; i < s.size() ; i++)
        {
           // for( j = 1 ; j <= s.size()-(i+1) ; j++)
			for( j = i+1 ; j < s.size() ; j++)
            {
				int len = j-i;
                string g = s.substr(i,len);
                mymap[g]=1;
            }
        }
        string kk;
        int ansmin=s.size();
        map<string,int>::iterator it;
        for(it=mymap.begin();it!=mymap.end();it++)
        {
            string tmp = (*it).first;
            int len = tmp.size();
            int cnt;
             cnt=0;
            for( i = 0 ; i <= s.size()-len ;)
            {
                if(s.substr(i,len)==tmp)
                {
                    cnt++;
                    i+=len;
                }
				else
					i++;
            }
            ansmin=min(s.size()-cnt*len+cnt+len,ansmin);
        }
    //  cout<<kk<<endl;
        cout<<ansmin<<endl;
    }
    return 0;
}