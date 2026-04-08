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
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int p; cin >> p;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i < p; i++){
        if(a[i] != a[i+1]) cnt1++;
    }
    for(int i = p; i < n; i++){
        if(a[i] != a[i+1]) cnt2++;
    }
    cout << (max(cnt1, cnt2) & 1 ? max(cnt1, cnt2) + 1: max(cnt1, cnt2)) << endl;
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