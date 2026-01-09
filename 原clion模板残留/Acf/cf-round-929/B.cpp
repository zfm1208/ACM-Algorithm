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
    int n; cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    rep(i,1,n) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 3 == 0){
        cout << 0 << endl;
        return;
    }
    rep(i,1,n) a[i] = a[i] % 3;
    sort(a.begin() + 1, a.end());
    int k = sum % 3;
    if(k == 1){
        rep(i,1,n) {
            if(a[i] == 1){
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }else if(k == 2){
        int cnt = 0;
        int p = 0;
        rep(i,1,n){
            if(a[i] == 2){
                cout << 1 << endl;
                return;
            }
            if(a[i] == 1) p++;
            if(a[i] == 0) cnt++;
        }
        if(cnt != 0 || p >= 2){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}