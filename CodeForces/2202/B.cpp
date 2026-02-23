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
/*
    T:ababa
    T:abab
*/
void solve(){
    int n;cin >> n;
    string s; cin >> s;
    if(n&1){
        if(s[0] == 'b'){
            cout << "NO" << endl;
            return;
        }
        for(int i = 1; i < n; i+=2){
            if(s[i] == s[i+1] && s[i] != '?'){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }else{
        for(int i = 0; i < n; i+=2){
            if(s[i] == s[i+1] && s[i] != '?'){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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