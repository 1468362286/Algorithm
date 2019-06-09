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
const int maxn = 150010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
vector<int>Va,Vb,Vc,Vd,ans;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,A,B,C,D,i,j;
	string s1,s2;
	while(cin>>n)
	{
		cin>>s1>>s2;
		A=0,B=0,C=0,D=0;
		for( i = 0 ; i < n ; i++)
		{
			if(s1[i]=='0'&&s2[i]=='0')
				A++,Va.push_back(i+1);
			else if(s1[i]=='0'&&s2[i]=='1')
				B++,Vb.push_back(i+1);
			else if(s1[i]=='1'&&s2[i]=='0')
				C++,Vc.push_back(i+1);
			else
				D++,Vd.push_back(i+1);
		}
		int ans_a=0,ans_b=0,ans_c=0,ans_d=0;
		int flag=0;
		for( i = 0 ; i <= A ; i++)
			for( j = 0 ; j <= B ; j++)
			{
				int d = (B+D-j)-(n/2-i-j);
				int c = n/2-i-j-d;
				if(d>=0&&d<=D&&c>=0&&c<=C)
				{
					flag=1;
					ans_a=i,ans_b=j,ans_c=c,ans_d=d;
					break;
				}
			}
		if(!flag)
		{
			cout<<-1<<endl;
			continue;
		}
		for( i = 0 ; i < ans_a ; i++)
			ans.push_back(Va[i]);
		for( i = 0 ; i < ans_b ; i++)
			ans.push_back(Vb[i]);
		for( i = 0 ; i < ans_c ; i++)
			ans.push_back(Vc[i]);
		for( i = 0 ; i < ans_d ; i++)
			ans.push_back(Vd[i]);
		sort(ans.begin(),ans.end());
		for( i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}		