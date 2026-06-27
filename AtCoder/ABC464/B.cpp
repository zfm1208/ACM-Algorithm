#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int h, w; cin >> h >> w;
    vector<string> s(h + 1);
    for(int i = 1; i <= h; i++){
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int up = h, dn = 1;
    int l = w, r = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(s[i][j] == '#'){
                up = min(up, i);
                dn = max(dn, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    for(int i = up; i <= dn; i++){
        for(int j = l; j <= r; j++){
            cout << s[i][j];
        }
        cout << endl;
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