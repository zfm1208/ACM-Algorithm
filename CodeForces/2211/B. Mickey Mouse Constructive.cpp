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
const int N = 1e6, mod = 676767677, inf = 1e18 + 5;
/*
    x 个 1, y 个 -1
    sum = x - y
    k 份 -> 每一份 = sun / k
*/
void solve(){
    int x,y; cin >> x >> y;
    int sum = abs(x - y);
    int cnt = 0;
    for(int i = 1; i*i <= sum; i++){
        if(sum % i == 0){
            cnt++;
            if(i * i != sum) cnt++;
        }
    }
    if(sum == 0) cnt = 1;
    // cout << cnt << endl;
    cout << cnt % mod << endl;
    if(x >= y) {
        rep(i,1,x) cout << 1 << " ";
        if(y == 0) cout << endl;
        else rep(i,1,y) cout << -1 << " \n"[i == y];
    }else{
        rep(i,1,y) cout << -1 << " ";
        if(x == 0) cout << endl;
        else rep(i,1,x) cout << 1 << " \n"[i == x];
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