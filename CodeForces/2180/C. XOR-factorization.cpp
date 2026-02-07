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
    int n,k; cin >> n >> k;
    if(k&1){
        rep(i,1,k) cout << n << " \n"[i==k];
    }else{
        vector<int> ans(k),vis(k);
        for(int i = 30; i >= 0; i--){
            vector<int> a; 
            vector<int> b;
            for(int i = 0; i < k; i++) {
                if(vis[i]) b.pb(i);
                else a.pb(i);
            }            
            if((n >> i) & 1){
                if(a.size()){
                    vis[a.front()] = 1;
                    for(auto x: a) ans[x] += (1 << i);
                    for(auto x: b) ans[x] += (1 << i);
                    ans[a.front()] -= (1 << i);
                }else{
                    for(auto x: b) ans[x] += (1 << i);
                    ans[b.front()] -= (1 << i);
                }
            }else{
                for(int x : b) ans[x] += (1LL << i); 
                if(b.size() & 1) ans[b.front()] -= (1 << i);               
            }
        }
        rep(i,0,k-1) cout << ans[i] << " \n"[i == k-1];
    }
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