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
/*
    1 3 4   2 5 6

    5 2 4   8 3 9  7 1 6

    4       8      6

    1 4 5   2 6 7  3 8 9
*/
void solve(){
    int n; cin >> n;
    vector<int> a(3 *n+1);
    int op = 1;
    for(int i = 1; i <= 3*n; i+=3){
        a[i] = op;
        op++;
    }
    for(int i = 1; i <= 3*n; i++){
        if(a[i] == 0) {
            a[i] = op;
            op++;
        }
    }
    rep(i,1,3*n) cout << a[i] << " \n"[i==3*n];
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