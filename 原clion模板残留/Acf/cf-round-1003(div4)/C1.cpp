#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
int a[N],b[N];
void solve() {
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    int pos = -inf;
    for(int i = 1; i <= n; i++){
        if(min(a[i], m - a[i]) >= pos){
            pos = min(a[i], m - a[i]);
        } else if(max(a[i], m - a[i]) >= pos){
            pos = max(a[i], m - a[i]);
        } else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
