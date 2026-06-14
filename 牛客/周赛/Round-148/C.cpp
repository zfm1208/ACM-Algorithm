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
    int n,k; cin >> n >> k;
    vii a(n+1);
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    if(k == 0){
        cout << n << endl;
        return;
    }
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    sort(a.begin()+1, a.end());
    int last = max(a[1] + k, a[2] + k - 1);
    int ans = 0;
    int l = -1, r = -1;
    for(int i = 1; i <= n; i++){
        int ll = max(a[i], last);
        int rr = a[i] + k;
        if(ll > rr) continue;

        if(l == -1){
            l = ll;
            r = rr;
        }else if(ll <= r + 1){
            r = max(r, rr);
        }else{
            ans += r - l + 1;
            l = ll;
            r = rr;
        }
    }
    if(l != -1){
        ans += r - l + 1;
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