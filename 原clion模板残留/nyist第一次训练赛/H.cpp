//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,k; cin >> n >> k;
    if(k == n-1){
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    if(k == 0){
        for(int i = n; i >= 1; i--){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    vector<int> a(n+1);
    vector<bool> vis(n+1,0);
    for(int i = 1; i <= n; i++) a[i] = i;
    vis[1] = 1;
    cout << 1 << " ";
    for(int i = n-k+1;i <= n; i++){
        cout << i << " ";
        vis[i] = 1;
    }
    for(int i=n; i >= 1; i--){
        if(!vis[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
