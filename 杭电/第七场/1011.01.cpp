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

void solve(){
    int n, k; cin >> n >> k;
    int g = gcd(n, k);
    string s; cin >> s;
    vector<int> f(g, 0); 
    for(int i = 0; i < n; i++){
        int j = n - 1 - i; 
        if(i > j) break;
        int u = i % g;
        int v = j % g;
        if(u > v) swap(u, v);
        if(s[i] != s[j]) {
            f[u] ^= 1;
        }
    }
    if(n & 1) f[(n / 2) % g] = 0;
    if(count(f.begin(), f.end(), 1) == 0){
        cout << "YES" << "\n"; 
    }else{
        cout << "NO" << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}