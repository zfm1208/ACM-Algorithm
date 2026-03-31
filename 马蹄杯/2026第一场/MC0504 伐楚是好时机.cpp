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
    string s; cin >> s;
    string ans;
    int n = s.size();
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == 'D') {
            if(ans.size()) ans.pop_back();
        }else{
            ans += c;
        }
    }
    if(ans.size() == 0)
        cout << "!!!!" << endl;
    else cout << ans << endl;
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