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
    string s; cin >> s;
    int ss = 0;
    int a = 0;
    int h = 0;
    int g = 0;
    int i = 0;
    int nn = 0;    
    for(auto &c: s){
        if(c == 'a' || c == 'A') a++;
        if(c == 's' || c == 'S') ss++;
        if(c == 'h' || c == 'H') h++;
        if(c == 'i' || c == 'I') i++;
        if(c == 'n' || c == 'N') nn++;
        if(c == 'g' || c == 'G') g++;
    }

    int ans = min({ss,h/2,a/2,nn,g,i});
    cout << ans << endl;
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