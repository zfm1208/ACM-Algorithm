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
int n,k;string s;
int check(int i){
    int cnt = 0;
    for(int j = i; j <= i + k - 1; j++){
        if(s[j] == 'W') cnt++;
    }
    return cnt;
}
void solve() {
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    string s1 = "";
    rep(i,1,k)s1 += 'B';
    int ans = inf;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++){
//        if(i + k - 1 > n)break;
        if(s.substr(i,k) == s1 && (i + k - 1 <= n)){
            cout << 0 << endl;
            return;
        }
//        ans = min(ans,check(i));
    }
    b[0] = 0;
    rep(i,1,n){
        if(s[i] == 'B') b[i] = b[i-1] + 1;
        else b[i] = b[i-1];
    }
    //B W W W B B W B W W W B B W
    // B B W B W
    // 1 2 2 3 3
    rep(i,1,n){
        if(i + k - 1 > n)break;
        int x = b[i+k-1] - b[i-1];
//        cout << x << endl;
        ans = min(ans,k-x);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
