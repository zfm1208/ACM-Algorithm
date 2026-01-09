//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
string s,t;
int lens,lent;
bool check(int l, int r){
    int pos = 0;
    for(int i = 0; i < lens; i++){
        if(l <= i && i <=r) continue;
        if(s[i] == t[pos])pos++;
    }
    return (pos==lent);
}
void solve() {
    cin >> s >> t;
    lens = s.size(), lent = t.size();
    int ans = 0;
    for(int l = 0; l < lens; l++){
        for(int r = l; r < lens; r++){
            if(check(l,r)){
                ans = max(ans,r - l + 1);
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
