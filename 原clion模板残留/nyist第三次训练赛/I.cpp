//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
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
    int n;cin>> n;
    vector<int> a(n+1),b(n+1);
    int m1=-1,m2=-2;
    rep(i,1,n) cin>>a[i],b[i]=a[i];
    sort(b.begin()+1,b.end());
    m1 = b[n];
    m2 = b[n-1];
    rep(i,1,n) {
        if(a[i]==m1){
            cout << m1-m2 << ' ';
        }else{
            cout << a[i]- m1<< ' ';
        }
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
