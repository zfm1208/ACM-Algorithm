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
    int n; cin >> n;
    unordered_map<int, int> mpx,mpy,mpz;
    vector<int> x(n+1), y(n+1), z(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> z[i];
        mpx[x[i]]++;
        mpy[y[i]]++;
        mpz[z[i]]++;
    }
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++){
        int d = max({mpx[x[i]]-1, mpy[y[i]]-1, mpz[z[i]]-1});
        mp[d]++;
    }
    int cnt = 0;
    for(int k = 0; k < n; k++){
        cout << cnt << " ";
        cnt += mp[k];
    }
    cout << endl;
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