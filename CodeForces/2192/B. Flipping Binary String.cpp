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
    string s; cin >> s;
    s = ' ' + s;
    vector<int> s0,s1;
    for(int i = 1; i <= n; i++){
        if(s[i] == '0'){
            s0.pb(i);
        }else{
            s1.pb(i);
        }
    }
    if(s1.size() % 2 == 0){
        cout << s1.size() << endl;
        for(int x: s1) cout << x << " ";
        cout << endl;
        return;
    }
    if(s0.size() & 1){
        cout << s0.size()<< endl;
        for(int x: s0)cout << x << " ";
        cout << endl;
        return;
    }
    cout << -1 << endl;
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