#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
void solve() {
    int n,m; cin >> n >> m;
    if(n==0){
        if(m==0){
            cout << "Yes" << endl;
            return;
        }else{
            cout << "No" << endl;
            return;
        }
    }
    if(m==0  && n!=0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
