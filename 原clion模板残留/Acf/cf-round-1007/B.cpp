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
bool check(int x){
    int t = sqrt(x);
    if(t * t == x) return true;
    else return false;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) a[i] = i;
    if(check((n+1) * n / 2)){
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    for(int i = n; i >= 1; i--){
        sum += a[i];
        if(check(sum)){
            if(i == 1){
                cout << -1 << endl;
                return;
            }
            swap(a[i], a[i-1]);
            sum -= a[i-1];
            sum += a[i];
            if(check(sum)){
                cout << -1 << endl;
                return;
            }
        }
    }
    for(int i = n; i >= 1; i--){
        cout << a[i] << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
