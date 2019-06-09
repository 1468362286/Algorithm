#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 987654321;
const LL MOD = 1e9+7;
const int N = 1e5+100;
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    string s;
    cin>>s;
    int n=s.size();
    int ans=n;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int len=j-i;
            string childStr=s.substr(i,len);
            int sum=0;
            for(int k=0;k<=n-len;){
                string cmpStr=s.substr(k,len);
                if(childStr==cmpStr){
                    k+=len;
                    sum++;
                }
                else
                    k++;
            }
            int temp=n-sum*(len-1)+len;
            ans=min(ans,temp);
        }
    cout<<ans;
    return 0;
}