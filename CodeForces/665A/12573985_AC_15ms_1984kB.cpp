#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<ctype.h>
using namespace std;
const int maxn=24*60;
int main()
{
   int a,b,ta,tb,h,m,cnt;
   char c;
   scanf("%d%d",&a,&ta);
   scanf("%d%d",&b,&tb);
   scanf("%d%c%d",&h,&c,&m);
   int st=h*60+m;
   int ed=h*60+m+ta;
   int s=5*60;
   cnt=0;
   while(s<60*24)
   {
       if(((s+tb)>st&&s<ed)||(s<ed&&s>st) )cnt++;
       s+=b;
   }
   printf("%d\n",cnt);
}