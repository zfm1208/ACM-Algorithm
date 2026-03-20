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
// wa 未解决
void solve(){
    int n; 
    if(!(cin >> n)) return; 
    
    vector<string> cun;
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        cun.pb(s);
    }
    int k; cin >> k;
    string op;
    getline(cin,op);
    string s;
    getline(cin,s);
    
    while(!s.empty() && s.back() == '\r'){
        s.pop_back();
    }
    
    int len = s.size();
    int cnt = 0;
    string ans = "";
    
    for(int i = 0; i < len; ){
        bool ok = 0;
        for(string tp: cun){
            int n_tp = tp.size();
            if(i + n_tp <= len && s.substr(i, n_tp) == tp){
                cnt++;
                ans += "<censored>";
                i += n_tp;  
                ok = 1;
                break;     
            }
        }
        if(ok == 0){
            ans += s[i];
            i++;
        }
    }
    if(cnt >= k){
        cout << cnt << endl;
        cout << "He Xie Ni Quan Jia!" << endl;
    }else{
        cout << ans << endl;
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