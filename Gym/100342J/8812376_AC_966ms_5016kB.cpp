#include <bits/stdc++.h>
using  namespace  std;

#define ll __int64
#define rep(i,k,n) for(int i=k;i<=n;i++)

const int N=1510;

char s[N][N];
bitset<N>bit1[N], bit2[N], tmp;
int n;

int  main(){
  freopen("triatrip.in","r",stdin);//必须加上，不然得WA
  freopen("triatrip.out","w",stdout);
  scanf("%d", &n);
  rep(i, 0, n-1){
    scanf("%s", s[i]);
    rep(j, 0, n-1){
      if(s[i][j] == '+')bit1[i].set(j), bit2[j].set(i);
    }
  }

  ll ans=0;
  rep(i, 0, n-1){
    rep(j, 0, n-1){
      if(bit1[i][j]){
        tmp = bit1[j] & bit2[i];
        ans += tmp.count();
      }
    }
  }
  printf("%I64d\n", ans / 3);
  return 0;
}