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
    int sum = 0;
    map<int,int> mp;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        mp[a[i]]++;
        mx = max(mx, a[i]);
    }
    vector<int> yz;
    for(int i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            if(i >= mx){
                yz.pb(i);
            }
            if(i*i != sum){
                if(sum / i >= mx) yz.pb(sum / i);
            }
        }
    }
    sort(yz.begin(),yz.end());
    vector<int> ans;
    for(int l: yz){
        bool ok = 1;
        for(auto [x,cnt]: mp){
            if(x == l) continue;
            if(mp.find(l - x) == mp.end()){
                ok = 0;
                break;
            }else if(mp[l-x] != cnt){
                ok = 0;
                break;
            }
        }
        if(ok) ans.pb(l);
    }
    for(int x: ans){
        cout << x << " ";
    } cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}