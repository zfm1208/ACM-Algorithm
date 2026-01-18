#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    找一个分界点i，使得t串前面和s串相同，且s[i] = ")"
    然后t串从s串后面找一个'(',然后再尽可能凑更多的合法括号对
    ( ) ( ) ( )  -> ( ( ) )
      p     p
    6 -> 4
    ( ( ) ( ( ) ) ) -> ( ( ( ) ) )
        p p
    8 -> 6
    ( ( ) ) ( ( ) ) ( ( ) ) ( ) -> ( ( ) ( ) ) ( ( ) ) ( )
          p p
    14 -> 12
    ( ( ( ) ( ) ) ( ) ) -> ( ( ( ) ) ( ) )
          p p
    10 -> 8
    ( ( ( ( ) ) ) ) -> X
    ans = n-2
*/
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int ans = -1;
    // 找后续)的数量
    vector<int> suf(n+2);
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1] + (s[i] == '(');
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == ')'){
            cnt++;
            if(suf[i+1] >= cnt+1){
                cout << n-2 << endl;
                return;
            }
            cnt--;
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}