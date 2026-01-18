#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 1, n-1) cin >> a[i];
    vector<int> diffs;
    vector<int> vis(n + 1);
    vector<int> mis; // 记录那些异常的差值（比如 >n 或者重复的）
    if(a[1] <= n){
        vis[a[1]] = 1;
    }else mis.pb(a[1]);
    for(int i = 2; i <= n-1; i++){
        int d = a[i] - a[i-1];
        if(d <= n && d >= 1 && !vis[d]){
            vis[d] = 1;
        } else {
            mis.pb(d);
        }
    }
    vector<int> c;
    rep(i, 1, n) if(!vis[i]) c.pb(i);
    if(mis.empty()) { cout << "YES" << endl; return;}
    if(mis.size() > 1){ cout << "NO" << endl; return;}
    if(c.size() != 2){ cout << "NO" << endl; return;}
    // 只有一个异常的大数，它必须等于剩下的两个小数之和
    if(c[0] + c[1] == mis[0]){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}