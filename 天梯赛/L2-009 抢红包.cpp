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
struct node {
    int id;
    int cnt;
    int sum;
};
void solve(){
    int n; cin >> n;
    vector<node> a(n+1);
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        a[i].id = i;
        int tot = 0;
        for(int j = 1; j <= k; j++){
            int op,x; cin >> op >> x;
            a[op].cnt++;
            a[op].sum += x;
            tot += x;
        }
        a[i].sum -= tot;
    }
    sort(a.begin() + 1, a.end(), [] (auto x, auto y){
        if(x.sum == y.sum){
            if(x.cnt == y.cnt) return x.id < y.id;
            return x.cnt > y.cnt;
        }
        return x.sum > y.sum;
    });
    for(int i = 1; i <= n; i++){
        int id = a[i].id;
        double x = a[i].sum * 1.0 / 100;
        cout << id << " " << fixed << setprecision(2) << x << endl;
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