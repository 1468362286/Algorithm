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
const int maxn = 200010;
const int inf = 0x3fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int n,k;
typedef struct node* pointer;

struct node
{
	int data;
	int id;
	pointer sub;
	pointer pre;
};
typedef pointer Linklist;

pair<int,pointer>mmax[maxn];
int ans[maxn];

bool cmp(pair<int,pointer> a,pair<int,pointer> b)
{
	return a.first>b.first;
}

void delnode(pointer p)
{
	pointer pre=p->pre;
	pointer sub=p->sub;
	if(pre!=NULL)
		pre->sub=sub;
	if(sub!=NULL)
		sub->pre=pre;
	p->data=-1;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int i,j;
	cin>>n>>k;
	Linklist l=new node;
	l->data=n;
	l->pre=l->sub=NULL;
	pointer p=l;
	for( i = 0 ; i < n ; i++)
	{
		int x;
		cin>>x;
		pointer xxx=new node;
		mmax[i]=make_pair(x,xxx);
		xxx->data=x;
		xxx->id=i;
		xxx->sub=p->sub;
		xxx->pre=p;
		p->sub=xxx;
		p=p->sub;
	}
	sort(mmax,mmax+n,cmp);
	int now=0;
	for( i = 0 ; i < n ; i++)
	{
		pointer ppp=mmax[i].second;
		if(ppp->data==-1)
			continue;
		if(ans[ppp->id]==0)
		{
			ans[ppp->id]=now+1;
			pointer pre=ppp->pre;
			pointer sub=ppp->sub;
			delnode(ppp);
			l->data--;
			for( j = k ; j>0&&pre!=NULL&&pre!=l;j--)
			{
				ans[pre->id]=now+1;
				pointer q=pre->pre;
				delnode(pre);
				pre=q;
				l->data--;
			}
			for( j = k ; j>0&&sub!=NULL ; j--)
			{
				ans[sub->id]=now+1;
				pointer q=sub->sub;
				delnode(sub);
				sub=q;
				l->data--;
			}
			now=1-now;
		}
		if(l->data==0)
			break;
	}
	for( i = 0 ; i < n ; i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}		