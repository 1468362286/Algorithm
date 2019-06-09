#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<sstream>  
#include<algorithm>  
#include<vector>  
#include<bitset>  
#include<set>  
#include<queue>  
#include<stack>  
#include<map>  
#include<cstdlib>  
#include<cmath>  
#define PI 2*asin(1.0)  
#define LL long long  
#define pb push_back  
#define pa pair<int,int>  
#define clr(a,b) memset(a,b,sizeof(a))  
#define lson lr<<1,l,mid  
#define rson lr<<1|1,mid+1,r  
#define bug(x) printf("%d++++++++++++++++++++%d\n",x,x)  
#define key_value ch[ch[root][1]][0]  
const int  MOD = 1000000007;  
const int N = 1e3+15;  
const int maxn = 5e5+1000;  
const int letter = 130;  
const int INF = 1e17;  
const double pi=acos(-1.0);  
const double eps=1e-8;  
using namespace std;  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
char a[N];  
int vis[N];  
int main(){  
    int z=1,f=0,n=0,p=1,cnt=0;  
    int max1=0,min1=0;  
    gets(a);  
    int len=strlen(a);  
    for(int i=0;i<len;i++){  
        if(a[i]=='-') f++,vis[cnt++]=-1;  
        else if(a[i]=='+') z++,vis[cnt++]=1;  
    }  
    for(int i=len-1;a[i]>='0'&&a[i]<='9'&&i>=0;i--) n+=p*(a[i]-'0'),p*=10;  
    max1=z*n-f,min1=z-f*n;  
    if(!(min1<=n&&n<=max1)){  
        puts("Impossible");  
        return 0;  
    }  
    puts("Possible");  
    int ff,zz;  
    for(zz=z*n;zz>=z;zz--){  
        ff=zz-n;  
        if(f<=ff&&ff<=f*n) break;  
    }  
    int zd=zz/z,zm=zz%z;  
    int fd,fm;  
    if(f) fd=ff/f,fm=ff%f;  
    int flag=0;  
    if(zm) flag=1,zm--;  
    printf("%d ",zd+flag);  
    for(int i=0;i<cnt;i++){  
        if(vis[i]==1){  
            flag=0;  
            if(zm)flag=1,zm--;  
            printf("+ %d ",zd+flag);  
        }  
        else {  
            flag=0;  
            if(fm) flag=1,fm--;  
            printf("- %d ",fd+flag);  
        }  
    }  
    printf("= %d\n",n);  
    return 0;  
} 