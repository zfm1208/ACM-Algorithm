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
    int n,x,y; cin >> n >> x >> y;
    string s; cin >> s;
    vector<int> p(n);
    for(auto &x:p) cin >> x;
    int tx = x,ty = y;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            x -= (1 + (p[i] >> 1));
        }else{
            y -= (1 + (p[i] >> 1));
        }
    }
    if((x<0 || y<0 ) || (accumulate(p.begin(),p.end(),0LL) > tx + ty)){
        cout << "NO" << endl;
        return;
    }
    // 若s全为'0'
    if(count(s.begin(),s.end(),'0') == n){
        if(tx < ty + n){
            cout << "NO" << endl;
            return;
        }
    }
    // 若s全为'1'
    if(count(s.begin(),s.end(),'1') == n){
        if(ty < tx + n){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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