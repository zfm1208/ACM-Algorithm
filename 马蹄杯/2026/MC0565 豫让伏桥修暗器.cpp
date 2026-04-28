#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int inf = 1e18;
struct node {
    int t,z;
};
void solve(){
    int n,m; cin >> n >> m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<node> a(n+1);
    for(int i = 1; i <= m; i++) {
        cin >> a[i].t >> a[i].z;
    }
    sort(a.begin()+1,a.end(),[&](node &x, node &y){
        if(x.t == y.t) return x.z < y.z;
        return x.t > y.t;
    });
    int ans = 0;
    multiset<int> st;
    int l = n;
    for(int i = 1; i <= m; i++){
        while(l >= a[i].t) {
            st.insert({v[l]});
            l--;
        }
        if(st.size() == 0) continue;
        auto it = st.upper_bound(a[i].z);
        --it;
        if(it != st.end() && *it <= a[i].z && st.find(*it) != st.end()){
            ans += *it;
            st.erase(it);
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}