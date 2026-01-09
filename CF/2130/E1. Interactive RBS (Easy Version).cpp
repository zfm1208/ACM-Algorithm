#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
// #define endl '\n'
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
// (x)(y)))
// (()()))) -> 4
// (()(())) -> 5
// ())()))) -> 2
// ())(())) -> 3
int ask(vector<int> e){
    cout << "? " << e.size() << " "; 
    for(auto &x : e) cout << x << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}
auto get(int l, int r){
    vector<int> e;
    for(int i = l; i <= r; i++){
        e.pb(i);
    }e.pb(l);
    return e;
}
void solve(){
    int n; cin >> n;
    vector<char> ans(n+1);
    int L = 1, R = n;
    while(L <= R){
        int mid = (L + R) >> 1;
        if(ask(get(1,mid))){
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }
    // (s[L],s[R]) -> ()  or  )(
    if(ask({R,L})) swap(L,R);
    for(int i = 1; i + 1 <= n; i+=2){
        int op = ask({L,i,R,L,i+1,R,R,R});
        if(op == 2){
            ans[i] = ')';
            ans[i+1] = ')';
        }else if(op == 3){
            ans[i] = ')';
            ans[i+1] = '(';
        }else if(op == 4){
            ans[i] = '(';
            ans[i+1] = ')';
        }else if(op == 5){
            ans[i] = '(';
            ans[i+1] = '(';
        }
    }
    if(n&1) ans[n] = ask({n,R}) ? '(' : ')';
    cout << "! ";
    rep(i,1,n) cout << ans[i];
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}