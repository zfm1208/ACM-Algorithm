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
string tp = "<censored>";
string nb = "He Xie Ni Quan Jia!";

void solve(){
    int n; cin >> n;
    // 不要使用set，可能会有相同的句子，不要去重！！
    // map<string,set<string>> mp;
    map<string, vector<string>> mp; 
    string du; 
    getline(cin,du);
    for(int q = 1; q <= n; q++){
        string s; 
        getline(cin, s);
        string t = s; 
        s = " " + s;
        string tp = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == ' ' && s[i] != ' '){
                tp += s[i];
            }
        }
        mp[tp].pb(t);
    }
    for(auto& p : mp){
        sort(p.se.begin(), p.se.end());
    }
    int q; cin >> q;
    getline(cin,du);
    while(q--){
        string s; 
        getline(cin, s);
        string t = s;
        s = " " + s;
        string tp = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == ' ' && s[i] != ' '){
                tp += s[i];
            }
        }
        if(mp.count(tp) == 0){
            cout << t << endl; 
        }else{
            bool ok = 1;
            for(const string &str : mp[tp]){
                if(!ok) cout << "|";
                cout << str;
                ok = 0;
            }
            cout << endl;
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