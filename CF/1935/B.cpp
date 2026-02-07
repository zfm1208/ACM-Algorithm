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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    将数组分成多段， 每一段的mex 都要等于全局MEX
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vis[a[i]]++;
    }
    int mex = 0;
    while(vis[mex]) mex++;
    int p = 0;
    vector<int> v(n+1);
    int m = 0;
    for(int i = 1; i <= n; i++){
        v[a[i]]++;
        while(v[m]) m++;
        if(m == mex) {
            p = i;
            break;
        }
    }
    vector<int> v2(n+1);
    int m2 = 0;
    for(int i = p+1; i <= n; i++){
        v2[a[i]]++;
        while(v2[m2]) m2++;
    }
    if(m2 == mex){
        cout << 2 << endl;
        cout << 1 << " " << p << endl;
        cout << p+1 << " " << n << endl;
    }else{
        cout << -1 << endl;
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}