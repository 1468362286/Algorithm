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
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
int n,x,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		int l=0,r=n-1;
		vector<int>vec;
		vector<char>opt;
		vec.clear(),opt.clear();
		while(l<=r)
		{
			if(vec.size()==0)
			{
				if(a[l]<a[r])
				{
					x=a[l];
					l++;
					opt.push_back('L');
				}
				else if(a[l]>a[r])
				{
					x=a[r];
					r--;
					opt.push_back('R');
				}
				else
				{
					int cnt1=0,cnt2=0;
					for( i = l+1 ; i <= r ; i++)
					{
						if(a[i]>a[i-1])
							cnt1++;
						else
							break;
					}
					for( i = r ; i >= l-1 ; i--)
					{
						if(a[i-1]>a[i])
							cnt2++;
						else
							break;
					}
					if(cnt1>=cnt2)
					{
						for( i = 0 ; i <= cnt1 ; i++)
							opt.push_back('L');
					}
					else
					{
						for( i = 0 ; i <= cnt2 ; i++)
							opt.push_back('R');
					}
					break;
				}
				vec.push_back(x);
			}
			else
			{
				int tmp = vec[vec.size()-1];
				if(a[l]>tmp)
				{
					if(a[r]>tmp)
					{
						if(a[l]>a[r])
						{
							x=a[r];
							r--;
							opt.push_back('R');
						}
						else if(a[l]<a[r])
						{
							x=a[l];
							l++;
							opt.push_back('L');
						}
						else
						{
							int cnt1=0,cnt2=0;
							for( i = l+1 ; i <= r ; i++)
							{
								if(a[i]>a[i-1])
									cnt1++;
								else
									break;
							}
							for( i = r ; i >= l-1 ; i--)
							{
								if(a[i-1]>a[i])
									cnt2++;
								else
									break;
							}
							if(cnt1>=cnt2)
							{
								for( i = 0 ; i <= cnt1 ; i++)
									opt.push_back('L');
							}
							else
							{
								for( i = 0 ; i <= cnt2 ; i++)
									opt.push_back('R');
							}
							break;
						}
					}
					else
					{
						x=a[l];
						l++;
						opt.push_back('L');
					}
				}
				else
				{
					if(a[r]>tmp)
					{
						x=a[r];
						r--;
						opt.push_back('R');
					}
					else
						break;
				}
				vec.push_back(x);
			}
		}
		cout<<opt.size()<<endl;
		for( i = 0 ; i < opt.size() ; i++)
			cout<<opt[i];
		cout<<endl;
	}
	return 0;
}		