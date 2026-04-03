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
    int n,m; cin >> n >> m;
    vector<int>a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int lst = sum;
    int cnt = 0;
    while(m--){
        int x; cin >> x;
        if(x == 1 || cnt == n) {
            cout << lst << endl;
            continue;
        }
        sum = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] != 0){
                a[i] /= x;
                if(a[i] == 0) cnt++;
                sum += a[i];
            }
        }
        lst = sum;
        cout << sum << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}