//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int a[N];
void f(){
    a[0] = 1;
    for(int i = 1; i <= N; i++){
        a[i] = a[i-1] * i % mod2;
    }
}
void solve() {
    string s; cin >> s;
    int len = s.size();
    s = " " + s;
    int cnt = 1,ans1 = 0,ans2 = 1;
    for(int i = 2; i <= len + 1; i++){
        if(s[i] == s[i-1]) cnt++;
        else{
            ans1+=(cnt-1);
            if(cnt>1) ans2 = ans2 * cnt % mod2;
            cnt = 1;
        }
    }
    cout << ans1 % mod2 << " " << ans2  * a[ans1] % mod2 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    f();
    cin >> T;
    while (T--) solve();
    return 0;
}
