//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int>a(n,1);
    for(int o = 0; o < n; o++){
        for(int i = 0; i < o; i++){
            a[i] = -1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] == a[j]){
                    ans++;
                }
            }
        }
        if(ans == k){
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
