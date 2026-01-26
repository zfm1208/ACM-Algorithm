#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
const int N = 1e6+10;
const int mod1 = 1e9+21, base1 = 233;
const int mod2 = 1e9+33, base2 = 131313;
#define ull unsigned long long
int hs1[N],hs2[N];
int p1[N],p2[N];
void init(){
    p1[0] = 1;
    p2[0] = 1;
    for(int i = 1; i < N; i++){
        p1[i] = (p1[i-1] * base1) % mod1;
        p2[i] = (p2[i-1] * base2) % mod2;
    }
}

void solve(){
    // string S,T;
    // cin >> S >> T;
    // int n = S.size(),m = T.size();
    // S = " " + S;
    // T = " " + T;
    // int j = 1, ans = 0;int i = 1;
    // for (; i <= n; i++) {
    //     if (S[i] != T[j]) j = 1;
    //     if (S[i] == T[j]) j++;
    //     if (j > m) {
    //         ans++;
    //         j = 1;
    //     }
    // }
    // cout << i << " " << j << endl;
    // cout << ans << endl;
    // return;
    /*
     *  aaac
     *  aac
    */

    int n; cin >> n;
    string s; cin >> s;
    bool ok = 0;
    s = '!' + s;
    for(int i = 1; i <= n; i++){
        hs1[i] = (hs1[i-1] * base1 + s[i]) % mod1;
        hs2[i] = (hs2[i-1] * base2 + s[i]) % mod2;
    }
    auto get = [&] (int l, int r, int hs[], int p[], int mod) -> int {
        return (hs[r] - (hs[l-1] * p[r-l+1]) % mod + mod) % mod;
    };
    for(int i = 2; i <= n; i++){
        int sum1 = get(1, i, hs1, p1, mod1);
        int suf1 = get(n-i+1, n, hs1, p1, mod1);  
        int sum2 = get(1, i, hs2, p2, mod2);
        int suf2 = get(n-i+1, n, hs2, p2, mod2);
        if(s[i] == s[1]){
            ok = 1;
            break;
        }
    }
    if(ok) cout << "Wrong Answer";
    else cout << "Correct";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    init();
    while(T--){
        solve();
    }
    return 0;
}