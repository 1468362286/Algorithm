//ITNOA
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cassert>
//#include <random>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define rep(i, s, e) for(int i = s; i < e; i ++)
#define X first
#define Y second

//typedef long long ll;
typedef long double ld;

const int maxN = 70*1000 + 5;
const int mod = 1000*1000*1000 + 7;
const int base = 701;
const int SQ = 500;
const int maxL = 17;

string s[maxN];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,i,j,k,len; cin >> n;
    vector<int> v;

    map<string, int> mp;
    for( i = 0; i < n; i++) {
        cin >> s[i];
        vector<string> v;
        for( j = 0; j < 9; j++) {
            string t;
            for( k = j; k < 9; k++) {
                t += s[i][k];
                v.push_back(t);
            }
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        for( j = 0; j < v.size(); j++)
            mp[v[j]] ++;
    }

    for( i = 0; i < n; i++) {
        bool br = false;
        for( len = 1; len <= 9; len++) {
            for( j = 0; j + len <= 9; j++)
                if(mp[s[i].substr(j, len)] == 1) {
                    cout << s[i].substr(j, len) << endl;
                    br = true;
                    break;
                }
            if(br)
                break;
        }
    }

    return 0;
}
