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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i] - i].pb(a[i]);
    }
    int sum = 0;
    for(auto [x,vc] :mp){
        if(vc.size() < 2) continue;
        sort(vc.rbegin(),vc.rend());
        for(int i = 0; i + 1 < vc.size(); i+=2){
            int w = vc[i] + vc[i+1];
            if(w > 0){
                sum += w;
            }else break;
        }
    }
    cout << sum << endl;
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