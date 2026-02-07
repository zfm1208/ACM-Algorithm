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

void solve(){
    int n,k; cin >> n >> k;
    set<int> st;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        st.insert(x);
        a[i] = x;
    }
    int ans = st.size();
    ans = min(ans,k-1) ;
    int x = 0;
    while(st.count(x))x++;
    ans = min(ans,x);
    cout << ans << endl;
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