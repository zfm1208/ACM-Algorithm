//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<iostream>
#include<cstdio>
#include<cmath>
#include<deque>
#include <vector>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> sum(2*n+2);
    rep(i,1,n) sum[i] = sum[i-1] + a[i];
    rep(i,n+1,n+k-1) sum[i] = sum[i-1] + a[i-n];
    int ans = -inf,l,r;
    deque<int> dq;
    for(int i = 1; i <= n+k-1; i++){
        while(!dq.empty() && sum[i-1] < sum[dq.front()]) dq.pop_back();
        while(!dq.empty() && dq.front() <= i-k-1) dq.pop_front();
        dq.push_back(i-1);
        if(sum[i] - sum[dq.front()] > ans){
            ans = sum[i] - sum[dq.front()];
            l = dq.front()+1, r = i;
        }
    }
    if(r > n) r %= n;
    cout << ans << " " << l << " " << r << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
