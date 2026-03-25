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
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre[i] = pre[i-1] + x;
    }
    for(int i = k; i <= n; i++){
        int sum = pre[i] - pre[i-k];
        double ans = sum * 1.0 / k;
        if(ans >= 1024){
            ans = ans / 1024.0;
            cout << fixed << setprecision(6) << ans <<  " MiBps" << endl;
        }else{
            cout << fixed << setprecision(6) << ans <<  " KiBps" << endl;
        }
    }
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