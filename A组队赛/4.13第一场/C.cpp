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

struct BIT {
    int n;
    vector<int> tr;
    BIT(int _n) : n(_n), tr(_n + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    BIT bit(n + 1); 
    vector<int> vis(n + 1);
    int mx = a[1]; 
    int flag = 0; 
    int cnt = 0;
    int ans = 0;
    vis[a[1]] = 1;
    bit.add(a[1], 1);
    cout << ans << (1 == n ? "" : " ");
    for(int i = 2; i <= n; i++){
        if(!vis[a[i]]){
            vis[a[i]] = 1;
            bit.add(a[i], 1);
        }
        if(a[i] == mx)  flag = 1;
        if(flag == 1 && a[i] <= mx)  cnt++;
        if(a[i] > mx){
            ans += 1 + cnt; 
            int old_mx = mx;
            mx = a[i]; 
            cnt = 0;
            flag = 0;
            ans += bit.query(old_mx + 1, mx); 
        } else {
            ans += bit.query(a[i] + 1, mx); 
        }
        cout << ans << (i == n ? "" : " ");
    }
    cout << endl;
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