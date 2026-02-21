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
    1 2 3 4 5
    1 4 3 2 5
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]] = i;
    } 
    vector<int> fa(n+1);
    iota(fa.begin(),fa.end(),0);
    auto find = [&](auto&self, int x) -> int {
        if(x == fa[x]) return x;
        return fa[x] = self(self,fa[x]);
    };
    auto link = [&](int x, int y)-> void {
        int fx = find(find,x);
        int fy = find(find,y);
        if(fx != fy) fa[fx] = fy;
    };
    for(int i = 1; 2 * i <= n; i++){
        link(i,2*i);
    }
    for(int i = 1; i <= n; i++){
        if(find(find,i) != find(find,b[i])){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
void solve1(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    auto get = [&] (int x) -> int {
        while(x % 2 == 0){
            x /= 2;
        }
        return x;
    };
    for(int i = 1; i <= n; i++){
        int x = a[i];
        if(get(i) != get(x)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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