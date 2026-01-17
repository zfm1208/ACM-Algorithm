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
    string s;cin >> s;
    int n = s.size();
    vector<int> pl, pr;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') pl.pb(i);
        else pr.pb(i);        
    }
    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        int m = t.size();        
        if((s[0] == 'L' && t[0] == 'R') || (s.back() == 'R' && t.back() == 'L')){
            cout << "NO" << endl;
            continue;
        }
        bool ok = true;
        int id = -1;
        for(char c : t){
            if(c == 'L'){
                int idx = upper_bound(pl.begin(), pl.end(), id) - pl.begin();
                if(idx == pl.size()){
                    ok = false;
                    break;
                }
                id = pl[idx];
            }else{ 
                int idx = upper_bound(pr.begin(), pr.end(), id) - pr.begin();
                if(idx == pr.size()) {
                    ok = false;
                    break;
                }
                id = pr[idx];
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
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