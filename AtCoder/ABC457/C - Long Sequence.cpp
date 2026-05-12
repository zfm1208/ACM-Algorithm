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

void solve(){
    int n,k; cin >> n >> k;
    vector<vector<int>> a(n+1);
    vector<int> L(n+1);
    for(int i = 1; i <= n; i++){
        cin >> L[i];
        a[i].resize(L[i]+1);
        for(int j = 1; j <= L[i]; j++){
            cin >> a[i][j];
        }
    }
    vector<int> C(n+1);
    for(int i = 1; i <= n; i++) cin >> C[i];
    for(int i = 1; i <= n; i++){
        int len = C[i] * L[i];
        if(k <= len){
            cout << a[i][(k-1)%L[i]+1] << endl;
            return;
        }else{
            k -= len;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}