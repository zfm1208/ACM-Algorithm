#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<string> s;
    for(int i = 1; i <= 2*n-2; i++){
        string t; cin >> t;
        if(t.size() == n - 1) s.pb(t);
    }
    string a = s[0];
    string b = s[1];
    reverse(a.begin(), a.end());
    if(a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}