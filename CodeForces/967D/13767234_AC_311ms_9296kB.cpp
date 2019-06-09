#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct data
{
	int val,pos;
	data(){};
	data(const int &val,const int &pos)
	{
		this->val=val;
		this->pos=pos;
	}
};

bool cmp(const data &a,const data &b)
{
	return a.val!=b.val?a.val<b.val:a.pos<b.pos;
}

int n,m1,m2;
const int maxn = 300005;
data a[maxn];
int premax[maxn],premaxpos[maxn],need[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	while(cin>>n>>m1>>m2)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>a[i].val;
			a[i].pos=i;
		}
		sort(a+1,a+n+1,cmp);
		for( i = 1 ; i <= n; ++i)
		{
			int tmp;
			if(m2%a[i].val==0)
			{
				tmp = m2/a[i].val;
			}
			else
			{
				tmp=m2/a[i].val+1;
			}
			if((n-i+1)-tmp>premax[i-1])
			{
				premax[i]=(n-i+1)-tmp;
				premaxpos[i]=i;
				need[i]=tmp;
			}
			else
			{
				premax[i]=premax[i-1];
				premaxpos[i]=premax[i-1];
				need[i]=need[i-1];
			}
		}
		int hou=0;
		for( i = n ; i >= 1 ; --i)
		{
			if(m2<=a[i].val*(n-i+1))
			{
				hou=i;
				break;
			}
		}
		if(!hou)
		{
			puts("No");
			return 0;
		}
		for( i = 1;  i <= n ; i++)
		{
			int tmp;
			if(m1%i==0)
			{
				tmp=m1/i;
			}
			else
			{
				tmp=m1/i+1;
			}
			data *p=lower_bound(a+1,a+n+1,data(tmp,0),cmp);
			if(p-a+i-1>n)
				continue;
			if(hou>=p-a+i)
			{
				puts("Yes");
				printf("%d %d\n",i,n-hou+1);
				for( j = p-a ; j < p-a+i ; ++j)
				{
					printf("%d%c",a[j].pos,j==p-a+i-1?'\n':' ');
				}
				for( j = hou ; j <= n ; j++)
				{
					printf("%d%c",a[j].pos,j==n?'\n':' ');
				}
				return 0;
			}
			else if(premax[p-a+-1]>=i)
			{
				puts("Yes");
				printf("%d %d\n",i,need[p-a-1]);
				for( j = p-a ; j <p-a+i ; ++j)
				{
					printf("%d%c",a[j].pos,j==p-a+i-1?'\n':' ');
				}
				int cnt=0;
				for( j = n ; j >= 1 ; j--)
				{
					if(j>=p-a&&j<p-a+i)
						continue;
					++cnt;
					printf("%d%c",a[j].pos,cnt==need[p-a+1]?'\n':' ');
					if(cnt==need[p-a+1])
						break;
				}
				return 0;
			}

		}
		puts("No");
	}
	return 0;
}