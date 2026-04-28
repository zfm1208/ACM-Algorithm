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
const int N = 1e6, mod = 676767677, inf = 1e18 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] >= 2) ans += a[i];
    }
    if(ans == 0){
        cout << 1 << endl;
        return;
    }
    for(int i = n; i >= 1; i--){
        if(a[i] >= 2){
            for(int j = i + 1; j <= n; j++){
                if(a[j] == 1){
                    cout << ans + 1 << endl;
                    return;
                }
            }
            cout << ans << endl;
            return;
        }
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