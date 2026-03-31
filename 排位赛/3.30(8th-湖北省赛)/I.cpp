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
    int cnt = 0;
    string op = s.substr(s.find('/') + 1);
    for(int i = 0; i < op.size(); i++){
        cnt = cnt * 10 + (op[i] - '0');
    }
    s.erase(s.find('/'));
    auto get = [&] (string t) -> string {
        vector<string> ans;
        int st = 0;
        for(int i = 1; i <= 3; i++){
            int pos = t.find('.', st);
            ans.pb(t.substr(st,pos-st));
            st = pos + 1;
        }
        ans.pb(t.substr(st));
        string res;
        for(int i = 0; i < 4; i++){
            string sp = ans[i];
            int x = 0;
            for(int j = 0; j < sp.size(); j++){
                x = x * 10 + (sp[j] - '0');
            }
            for(int p = 7; p >= 0; p--){
                if((x >> p) & 1) res += '1';
                else res += '0';
            }
        }
        return res;
    };
    s = get(s).substr(0,cnt);
    int n; cin >> n;
    while(n--){
        string t; cin >> t;
        t = get(t).substr(0,cnt);
        if(t == s) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
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