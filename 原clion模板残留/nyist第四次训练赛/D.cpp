//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
//#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int n,a[N],b[10];
void solve() {
    scanf("%d",&n);
    rep(i,1,n) scanf("%1d",&a[i]);
    rep(i,1,9) scanf("%d",&b[i]);
    rep(i,1,n){
        if(a[i] < b[a[i]]){
            for(int j = i;j <= n && a[j] <= b[a[j]]; j++)
                a[j] = b[a[j]];
            break;
        }
    }
    for(int i=1;i<=n;i++) printf("%d",a[i]);
}
signed main() {
    ios::sync_with_stdio(false);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
