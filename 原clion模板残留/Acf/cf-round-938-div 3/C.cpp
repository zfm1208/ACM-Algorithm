//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define uint unsigned long long
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int a[N];
void solve() {
    int n,k; cin >> n >> k;
    int sum = 0,pre = (k+1)/2,suf = k/2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum <= k){
        cout << n << endl;
        return;
    }
    int l,r;
    for(l = 1; l <= n; l++)
        if(pre >= a[l])pre -= a[l];
        else break;
    for(r = n; r >= 1; r--)
        if(suf >= a[r]) suf -= a[r];
        else break;
    cout << n - ( r - l + 1 ) << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
