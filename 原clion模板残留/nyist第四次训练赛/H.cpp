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
int n,m;
int s[10][10];
int a[205][205];
int he;
int dfs(int x){
    if(x == 1) return he;
    he = 0;
    int mn = inf;
    for(int i = 0; i <= 9; i++){
        mn = min(mn,s[x][i]);
    }
    he += mn;
    if(he < s[x][1]) dfs(mn);
    else return s[x][1];
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int w = a[i][j];
            int temp = s[w][1];
            sum += min(temp,dfs(w));
        }
    }
    cout << sum << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
