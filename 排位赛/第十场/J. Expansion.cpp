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

void solve(){
    int n; cin >> n;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    if(accumulate(a.begin()+1,a.end(),0LL) < 0LL){
        cout << -1 << endl;
        return;
    }
    int ans = n;
    int mx = -inf;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += pre[i];
        if(sum < 0){
            if(mx <= 0) {
                cout << -1 << endl;
                return;
            }
            int time = (-sum + mx - 1) / mx;
            ans += time;
            sum += mx * time;
        }
        mx = max(mx, pre[i]);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}