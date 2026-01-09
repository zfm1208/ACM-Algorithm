//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,c,d; cin >> n >> c >> d;
    vector<int> a(n*n);
    for(int i = 0; i < n * n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int x = a[n*n-1] - (n-1) * c - (n-1) * d;
//    for(int i = 0; i < n * n; i++) cout << a[i] << " ";
//    cout << endl;
    if(x == a[0]) {
        vector<vector<int>> b(n+1, vector<int>(n+1));
        b[0][0] = x;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                b[i+1][j] = b[i][j] + c;
                b[i][j+1] = b[i][j] + d;
            }
        }
        vector<int> e(n*n);
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                e[cnt] = b[i][j];
                cnt++;
            }
        sort(e.begin(), e.end());
//        for(int i = 0; i < n * n; i++) cout << e[i] << " ";
        for(int i = 0; i < n * n; i++){
            if(e[i] != a[i]) {
                cout << "NO" << endl;
                return;
            }

        }
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
