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
    int a = 0,b = 0;
    bool ok = 0; 
    vector<string> arr(n+1);
    rep(i,1,n) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        string s = arr[i]; 
        int p = s.find('-');
        int x = stoi(s.substr(0, p));
        int y = stoi(s.substr(p + 1));
        int t = x + y;
        int op = (((t + 1) / 2) % 2 == 0) ? 0 : 1;
        int aa = (op == 0) ? x : y;
        int bb = (op == 0) ? y : x;
        if(aa == 11 && bb == 11){
            cout << "error " << i << "\n";
            return;
        }
        else if (aa < a || bb < b) {
            cout << "error " << i << "\n";
            return;
        }
        else if (ok && (aa != a || bb != b)) {
            cout << "error " << i << "\n";
            return;
        }
        a = aa;
        b = bb;
        if(aa == 11 || bb == 11)  ok = 1;
    }

    cout << "ok\n";
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