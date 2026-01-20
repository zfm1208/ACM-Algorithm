#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2e5+10,mod = 1e9+7;

void solve(){
    int x,y,a,b; cin >> x >> y >> a >> b;
    int gcd = __gcd(x,y);
    x/=gcd,y/=gcd;
    int sum = x+y;
    int cnt = 0;
    for(int i = 0; i <= 62; i++){
        if(1LL << i == sum){
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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