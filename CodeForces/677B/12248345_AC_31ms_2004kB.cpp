#include<stdio.h>  
#include<string.h>  
using namespace std;  
int main()  
{  
    int n,m,k;  
    __int64 ans=0;  
    scanf("%d%d%d",&n,&m,&k);  
    int x,temp=0;  
    for(int i=0;i<n;i++)  
    {  
        scanf("%d",&x);  
        if(x+temp>m)  
        {  
            ans++;  
            temp=0;  
        }  
        temp=temp+x;  
        ans=ans+temp/k;  
        temp=temp%k;  
    }  
    if(temp)ans++;  
    printf("%I64d\n",ans);  
}  