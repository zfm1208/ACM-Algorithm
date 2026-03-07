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
    int a,b,c,k; cin >> a >> b >> c >> k;
    for(int i = 1; i <= k; i++){
        int ta = (b+c)/2;
        int tb = (a+c)/2;
        int tc = (a+b)/2;
        a = ta;
        b = tb;
        c = tc;
        if(a == b && b == c){
            break;
        }
    }
    cout << a << " " << b << " " << c << endl;
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