//#include<bits/stdc++.h>
#include <iostream>
using namespace std;
//typedef long long LL;
#define INF 0x3f3f3f3f
int d[1000005];
int main()
{
  int n,q,ssum=2,sum=1,a,x,i;
  scanf("%d%d",&n,&q);
  for( i=0;i<q;i++)
  {
    scanf("%d",&a);
    if(a==1)
    {
      scanf("%d",&x);
      sum+=x;
      while(sum>n) sum-=n;
      while(sum<=0) sum+=n;
      ssum+=x;
      while(ssum>n) ssum-=n;
      while(ssum<=0) ssum+=n;
    }
    else
    {
      if(sum%2)
      {
        sum++;
      }
      else
      {
        sum--;
      }
      if(ssum%2)
      {
        ssum++;
      }
      else ssum--;
      if(sum<=0) sum=n;
      if(sum>n) sum=1;
      if(ssum<=0) ssum=n;
      if(ssum>n) ssum=1;
    }
  }
  for( i=1;i<=n;i++)
  {
    d[i]=i;
  }
  int ans=0,cnt=0;
  //printf("%d %d\n",sum,ssum);
  for( i=1;i<=n;i+=2)
  {
    d[sum]=i;
    sum+=2;
    sum%=n;
    if(sum==0) sum=n;
  }
  for( i=2;i<=n;i+=2)
  {
    d[ssum]=i;
    ssum+=2;
    ssum%=n;
    if(ssum==0) ssum=n;
  }
  for( i=1;i<n;i++)
  {
    printf("%d ",d[i]);
  }
  printf("%d\n",d[n]);
  return 0;
}