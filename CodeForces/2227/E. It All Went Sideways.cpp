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
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<int> suf(n+2);
    suf[n] = a[n];
    for(int i = n-1; i >= 1; i--){
        suf[i] = min(suf[i+1], a[i]);
    }
    int sum1 = 0;
    for(int i = 1; i <= n; i++){
        sum1 += suf[i];
    }
    int ans = sum - sum1;
    int mx = 1;
    int cnt = 1;
    for(int i = 2; i <= n; i++){
        if(suf[i] == suf[i-1]){
            cnt++;
        }else{
            mx = max(mx, cnt);
            cnt = 1;
        }
         mx = max(mx, cnt);
    }
    mx = max(mx, cnt);
    cout << ans + mx - 1 << endl;
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