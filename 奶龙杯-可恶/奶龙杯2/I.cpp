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
const int N = 1e6, mod = 1e9, inf = 1e18 + 5;
int qpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
//结论:如果两个数A和B的后6位相同，那么A^A和B^B的后6位通常也相同,在x与10互质的情况下
int v[N+10];
void init(){
    for(int i = 1; i <= N; i++){
        v[qpow(i,i) % N] = i;
    }
}
void solve(){
    int n; cin >> n;
    for(int i = 0; i < 1000; i++){
        int x = i*N+v[n%N];
        if(qpow(x,x) == n){
            cout << x << endl;
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}