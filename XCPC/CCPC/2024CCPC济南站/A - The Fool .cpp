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
    int n,m,k; cin >> n >> m >> k;
    vector<string> a(n+1);
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        s = " " + s;
        a[i] = s;
    }
    string s1 = a[1].substr(1,k);
    int s,t;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m * k; j+=k){
            string tp = a[i].substr(j,k);
            if(tp != s1){
                s = i,t = (j-1)/k+1;
                cnt++;
            }
        }
    }
    if(cnt == 1){
        cout << s << " " << t << endl;
    }
    else cout << 1 << " " << 1 << endl;
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