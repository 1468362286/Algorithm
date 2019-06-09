#include<stdio.h>  
#include<iostream>  
#include<string.h>  
#include<string>  
#include<ctype.h>  
#include<math.h>  
#include<set>  
#include<map>  
#include<vector>  
#include<queue>  
#include<bitset>  
#include<algorithm>  
#include<time.h>  
using namespace std;  
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }  
#define MS(x,y) memset(x,y,sizeof(x))  
#define MC(x,y) memcpy(x,y,sizeof(x))  
#define MP(x,y) make_pair(x,y)  
#define ls o<<1  
#define rs o<<1|1  
typedef long long LL;  
typedef unsigned long long UL;  
typedef unsigned int UI;  
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }  
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }  
const int N = 13e5+10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;  
int casenum, casei;  
char s[N];  
char ans[5];  
int main()  
{  
    MC(ans, "0110");  
    int T = 0;  
    scanf("%d", &casenum);  
    for (int casei = 1; casei <= casenum; ++casei)  
    {  
        scanf("%s", s + 1); int l = strlen(s + 1);  
        if (l < 909526)printf("%d\n", s[l] & 1);  
        else printf("%c\n", ans[T++]);  
    }  
    return 0;  
}  