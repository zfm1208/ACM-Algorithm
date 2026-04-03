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
struct node{
    int val;
    int i,j,k;
    bool operator<(const node & tp) const {
        return val > tp.val;
    };
};
void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1),b(n+1),c(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    rep(i,1,n) cin >> c[i];
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    sort(c.begin()+1,c.end());
    priority_queue<node> pq;
    set<array<int,3>> st;
    pq.push({a[1] * b[1] * c[1], 1, 1, 1});
    st.insert({1,1,1});
    while(m--){
        auto [x,i,j,k] = pq.top();
        cout << x << " ";
        pq.pop();
        if (i + 1 <= n && st.find({i+1,j,k}) == st.end()){
            st.insert({i + 1, j, k});
            pq.push({a[i + 1] * b[j] * c[k], i + 1, j, k});
        }
        if (j + 1 <= n && st.find({i, j + 1, k}) == st.end()) {
            st.insert({i, j + 1, k});
            pq.push({a[i] * b[j + 1] * c[k], i, j + 1, k});
        }
        if (k + 1 <= n && st.find({i, j, k + 1}) == st.end()) {
            st.insert({i, j, k + 1});
            pq.push({a[i] * b[j] * c[k + 1], i, j, k + 1});
        }
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