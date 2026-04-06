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
    string s;
    int x;
};
void solve(){
    int n, g, k; 
    cin >> n >> g >> k;
    vector<node> a(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i].s >> a[i].x;
        if(a[i].x >= 60 && a[i].x < g) ans += 20;
        else if(a[i].x >= g) ans += 50; 
    }
    sort(a.begin() + 1, a.end(), [](const node& aa, const node& bb){
        if(aa.x == bb.x) return aa.s < bb.s;
        return aa.x > bb.x;
    });
    cout << ans << '\n';
    int rank = 1; 
    for(int i = 1; i <= n; i++){
        if(i > 1 && a[i].x != a[i-1].x){
            rank = i;
        }
        if(rank > k) break;
        cout << rank << " " << a[i].s << " " << a[i].x << endl;
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