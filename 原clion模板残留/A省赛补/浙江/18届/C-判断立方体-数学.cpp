//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double PI = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int dis(int x1,int y1,int z1,int x2,int y2,int z2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}
void solve() {
    vector<pair<pii,int>> a(8+1);
    map<int,int> mp;
    for(int i =1; i <= 8 ; i++){
        int x,y,z; cin >> x >> y >> z;
        a[i] = {{x,y},z};
    }
    for(int i = 1; i <= 8; i++){
        for(int j = i+1; j <= 8; j++){
            mp[dis(a[i].fi.fi,a[i].fi.se,a[i].se,a[j].fi.fi,a[j].fi.se,a[j].se)]++;
        }
    }
    vector<pii> v(5);
    int cnt=1;
    if(mp.size() != 3){
        cout << "No" << endl;
        return;
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        v[cnt].fi = it->se;
        v[cnt].se = it->fi;
        cnt++;
    }
//    for(int i = 1; i <= 3; i++){
//        cout << v[i].fi << " " << v[i].se << endl;
//    }
    if(v[1].fi == v[2].fi && v[2].fi == 3*v[3].fi){
        if(2*v[1].se == v[2].se && 3*v[1].se == v[3].se){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}