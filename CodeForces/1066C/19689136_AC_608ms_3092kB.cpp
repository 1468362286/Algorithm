#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 200010;
typedef _int64 ll;
int pos[maxn],vist[maxn];
vector<int>vec_l,vec_r;
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int q,x;
	string opt;
	cin>>q;
	memset(vist,0,sizeof(vist));
	vec_l.clear(),vec_r.clear();
	int cnt_l=0,cnt_r=0;
	while(q--)
	{
		cin>>opt>>x;
		if(opt[0]=='L')
		{
			cnt_l++;
			vec_l.push_back(x);
			pos[x]=cnt_l;
			vist[x]=1;
		}
		else if(opt[0]=='R')
		{
			cnt_r++;
			vec_r.push_back(x);
			pos[x]=cnt_r;
			vist[x]=2;
		}
		else
		{
			if(vist[x]==1)
			{
				cout<<min(vec_l.size()-pos[x],vec_r.size()+pos[x]-1)<<endl;
			}
			else if(vist[x]==2)
			{
				cout<<min(vec_r.size()-pos[x],vec_l.size()+pos[x]-1)<<endl;
			}
		}
	}
	return 0;
}