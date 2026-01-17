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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int n = s.size();
    int first = -1, last = -1;
    rep(i, 0, n - 1) if(s[i] == '1') {
        if(first == -1) first = i;
        last = i;
    }
    
    if(first == -1) { 
        cout << 0 << endl;
        return;
    }
    int ans = a;
    int cnt0 = 0;
    rep(i, first, last){
        if(s[i] == '0') cnt0++;
        else {
            if(cnt0 > 0){
                ans += min(a, cnt0 * b);
                cnt0 = 0;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}