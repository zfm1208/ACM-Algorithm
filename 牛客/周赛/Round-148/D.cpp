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
    l-> r
    6  7
    6 110
    7 111
    ^ 001
    110 ^ 001 = 111
    111 ^ 111 = 000

    9  1001
    14 1110
    ^ 0111
    1001 ^ 0100 =  1101  
*/
void solve(){
    int l, r;
    cin >> l >> r;
    int x = l ^ r;
    int p = 1;
    while(p * 2 <= x){
        p *= 2;
    }
    // cout << "p: " << p << " x:" << x << endl;
    int mid = l ^ p;
    vii ans;
    ans.pb(l);
    if(mid != r){
        ans.pb(mid);
    }
    ans.pb(r);
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}