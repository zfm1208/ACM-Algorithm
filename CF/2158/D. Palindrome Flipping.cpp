#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    s = " " + s;
    t = " " + t;
    vector<pii> ans;
    int nn = n-4;
    for(int i = 1; i <= nn; i++){
        if(s[i] == t[i]) continue;
        // 11  -> 00
        // 0      0
        if(s[i] == s[i+1]) {
            for(int j = i; j <= i+1; j++){
                s[j] = (s[j] == '0') ? '1' : '0';
            }
            ans.pb({i,i+1});
        }else if(s[i] == s[i+2]){
            // 101  ->   010
            // 0         0
            for(int j = i; j <= i+2; j++){
                s[j] = (s[j] == '0') ? '1' : '0';
            }
            ans.pb({i,i+2});
        }else{
            // 100  -> 111  -> 001
            // 0       0       0
            for(int j = i+1; j <= i+2; j++){
                s[j] = (s[j] == '0') ? '1' : '0';
            }
            ans.pb({i+1,i+2});
            for(int j = i; j <= i+1; j++){
                s[j] = (s[j] == '0') ? '1' : '0';
            }
            ans.pb({i,i+1});
        }
    }
    string now = s.substr(nn+1,4);
    string pos = t.substr(nn+1,4);
    if(now == pos){
        cout << ans.size() << endl;
        for(auto &[x,y] : ans){
            cout << x << " " << y << endl;
        }
        return;
    }
    auto check = [&] (string s, int l, int r) -> bool {
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;r--;
        }
        return true;
    };
    // 考虑后4+位，可以通过bfs暴力求所有答案
    /*
        1010 -> 0100 -> 0111 -> 0000 -> 0110
        0110
    */

    // string1 是由 string2 通过 [l,r] 得来的
    // string2 是 string1 的前驱
    map<string,pair<string,pii>> pre;
    queue<string> q;
    q.push(now);
    pre[now] = {"",{0,0}};
    while(!q.empty()){
        string u = q.front();
        q.pop();
        if(u == pos) break;
        int len = u.size();
        for(int l = 0; l < len; l++){
            for(int r = l + 1; r < len; r++){
                if(check(u,l,r)){
                    string v = u;
                    for(int k = l; k <= r; k++){
                        v[k] = (v[k] == '1') ? '0' : '1';
                    }
                    if(pre.find(v) == pre.end()){
                        pre[v] = {u,{nn+1+l,nn+1+r}};
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<pii> tp;
    string cur = pos;
    while(cur != now){
        tp.pb(pre[cur].se);
        cur = pre[cur].fi;
    }

    reverse(tp.begin(), tp.end());
    for(auto op : tp) ans.pb(op);

    cout << ans.size() << endl;
    for(auto &[x,y] : ans){
        cout << x << " " << y << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}