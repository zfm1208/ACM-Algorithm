#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    1 3 5 7 8 -> Alice
    1 3 4 6 7 8 8
        1 2 3 4 5
        j o j o j
        o j o j o

*/
void solve(){
    int n;cin>> n;
    vii a(n+1),ji,ou;
    int cnt_ji = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i&1) ji.pb(a[i] % 2 == 1 ? -1 : 1);
        else ou.pb(a[i] % 2 == 1 ? -1 : 1);
        if(a[i] & 1) cnt_ji++;
    }
    int mx = 0, cur = 0;
    for (int x : ji) {
        cur = max(0LL, cur + x);
        mx = max(mx, cur);
    }

    cur = 0;
    int mx1 = 0;
    for (int x : ou) {
        cur = max(0LL, cur + x);
        mx1 = max(mx1, cur);
    }

    mx = max(mx, mx1);

    if (cnt_ji + mx > n - (cnt_ji + mx)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
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