#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    vii a(n+1);
    rep(i,1,n) cin >> a[i];
    int ans = inf;
    for(int k = 1; k <= n; k++){
        int x = a[k];
        int cnt = 0;
        // set<int> st;
        int c1 = 0, c2 = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == x) continue;
            else  if(a[i] > x) c1++;
            else c2++;
        }
        // if(st.size() == 1) continue;
        // ans = min(ans, (int)(st.size() + 1) / 2);
        ans = min(ans, min(c1,c2) + abs(c1-c2));
    }
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