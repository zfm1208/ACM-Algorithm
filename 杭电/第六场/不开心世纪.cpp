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
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> mp(m+1);
    int cnt = 0;
    int len = inf;
    int l = 1;
    for(int r = 1; r <= n; r++){
        if(a[r] <= m){
            if(mp[a[r]] == 0) cnt++;
            mp[a[r]]++;
        }
        while(cnt == m){
            len = min(len, r-l+1);
            if(a[l] <= m){
                mp[a[l]]--;
                if(mp[a[l]] == 0) cnt--;
            }
            l++;
        }
    }
    if(len == inf){
        cout << -1 << endl;
    }else{
        cout << len - m << endl;
    }
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