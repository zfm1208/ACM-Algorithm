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
    int n, ex, ey; cin >> n >> ex >> ey;
    string t; cin >> t;
    string s = "";
    rep(i,1,1e3) s += t;
    int x = 0,y = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i]=='N')
            y++;
        else if (s[i]=='S')
            y--;
        else if (s[i]=='E')
            x++;
        else
            x--;
        if(x==ex && y==ey){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}