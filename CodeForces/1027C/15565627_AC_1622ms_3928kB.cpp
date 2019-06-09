#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
double ans=1e18,pre;
int s[N],n,i,j,ans1,ans2;
int  main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)cin>>s[i];
        sort(s+1,s+1+n);
        for(i=1,pre=-1;i<=n;i=j){
            for(j=i;s[j]==s[i]&&j<=n;j++);
            if(j-i>=4){ans=2;ans1=s[i];ans2=s[i];break;}
            if(j-i>=2&&pre>0&&pre/s[i]+s[i]/pre<ans){
                ans=pre/s[i]+s[i]/pre;
                ans1=pre;ans2=s[i];
            }
            if(j-i>=2)pre=s[i];
        }
        cout<<ans1<<" "<<ans1<<" "<<ans2<<" "<<ans2<<endl;
        ans=1e18;
    }
}