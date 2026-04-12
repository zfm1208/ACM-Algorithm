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
    string s,t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = " " + s;
    t = " " + t;
    vector<vector<int>> nxt(n+2, vector<int>(26, inf));
    for(int i = n; i >= 1; i--){
        for(int c = 0; c < 26; c++){
            nxt[i][c] = nxt[i+1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cur = i;
        bool ok = 1;
        for(int j = 1; j <= m; j++){
            cur = nxt[cur][t[j] - 'a'];
            if(cur > n){
                ok = 0;
                break;
            }
            cur++;
        }
        if(ok){
            ans += cur-i-1;
        }else{
            ans += n-i+1;
        }
    }
    cout << ans << endl;
}
void solve1() {
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    set<int> st;
    for(int x: t) st.insert(x);
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
        if(st.count(s[i])) {
            mp[s[i]].push_back(i);
        }
    }
    int res = 0;
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        int p = i-1;
        for(int j = 0; j < m; j++){
            auto it = upper_bound(mp[t[j]].begin(), mp[t[j]].end(), p);
            if(it == mp[t[j]].end()){
                ok = 0;
                break;
            }
           p = *it; 
        }
        if(ok == 0) break;
        res += n-p;
    }
    cout << n * (n + 1) / 2 - res << endl;;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}