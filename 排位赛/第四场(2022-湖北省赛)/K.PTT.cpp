#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2e5+10,mod = 1e9+7;
void solve(){
    int n; cin >> n;
    long double c; cin >> c;
    long double x;
    if(n >= 10000000){
        x = 2.0;
    }else if( n <= 9999999 && n > 9800000){
        x = 1.0 + (n - 9800000) / 200000.0;
    }else if(n <= 9800000){
        x = (n - 9500000) / 300000.0;
    }
    x = x + c;
    if (x < 0.0){
        x = 0.0;
    }
    cout << fixed << setprecision(7) << x << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}