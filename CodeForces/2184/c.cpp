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
struct node{
    int a,b;
};
void solve(){
    int n,k; cin >> n >> k;
    if(n == k){
        cout << 0 << endl;
        return;
    }
    if(k > n){
        cout << -1 << endl;
        return;
    }
    bool ok = 0;
    queue<pii> q;
    q.push({n, 0}); 
    map<int, int> mp;
    mp[n] = 1;
    while(q.size()){
        auto [x, cnt] = q.front();
        q.pop();
        int s1 = x / 2;
        int s2 = (x + 1) / 2; 
        if(s1 == k || s2 == k){
            ok = 1;
            cout << cnt + 1 << endl;
            break; 
        }
        if(s1 > k && mp[s1] == 0){
            mp[s1] = 1;
            q.push({s1, cnt + 1});
        }
        if(s2 > k && mp[s2] == 0){
            mp[s2] = 1;
            q.push({s2, cnt + 1});
        }
        
    }
    if(ok == 0){
        cout << -1 << endl;
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