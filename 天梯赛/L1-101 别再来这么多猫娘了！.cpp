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
string hh;

// 这一题14/15, 过了绝大多数分数, 赛时的话不用追求那一分了
void solve(){
    int n; cin >> n;
    getline(cin,hh);
    vector<string> cun;
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin,s);
        cun.pb(s);
    }
    int k; cin >> k;
    getline(cin,hh);
    string s; getline(cin,s);
    int len = s.size();
    string ans;
    int cnt = 0;
    for(int i = 0; i < len; i++){
        bool ok = 0;
        for(string s1 : cun){
            int n1 = s1.size();
            if(i + n1 <= len && s.substr(i,n1) == s1){
                cnt++;
                i += n1 - 1;
                ok = 1;
                ans += tp;
                break;
            }
        }
        if(ok == 0){
            ans += s[i];
        }
    }
    if(cnt >= k){
        cout << cnt << endl;
        cout << nb << endl;
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