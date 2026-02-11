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
    y - d(y) = x
*/
void solve(){
    int n; cin >> n;
    auto get = [&](int x)-> int {
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    map<int,int> mp;
    for(int i = n + 1; i <= n+10000; i++){
        mp[i - get(i)]++;
    }
    cout << mp[n] << endl;
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