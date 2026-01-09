#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,m; cin >> n >> m;
    vector<string> s(n+1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int cnt = 0;
    int cnt1 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '.') {
                cnt++;
                if(i != 1 || j != m){
                    cout << "No" << endl;
                    return;
                }
            }
            if(s[i][j] == 'C') cnt1++;
        }
    }
    if(s[1][m] == 'C'){cout << "No" << endl; return;}
    if(cnt > 1) {cout << "No" << endl; return;}
    if(3*cnt1 + cnt != n*m) {cout << "No" << endl; return;}
    map<pii,int> mp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'L') {
                if(j == 1 || s[i][j-1] != 'C'){
                    cout << "No" << endl;
                    return;
                }
                mp[{i,j-1}]++;
            }
            if(s[i][j] == 'R'){
                if(j == m || s[i][j+1] != 'C'){
                    cout << "No" << endl;
                    return;
                }
                mp[{i,j+1}]++;
            }
            if(s[i][j] == 'U'){
                if(i == 1 || s[i-1][j] != 'C'){
                    cout << "No" << endl;
                    return;
                }
                mp[{i-1,j}]++;
            }
            if(s[i][j] == 'D'){
                if(i == n || s[i+1][j] != 'C'){
                    cout << "No" << endl;
                    return;
                }
                mp[{i+1,j}]++;
            }
        }
    }
    for(auto x : mp){
        if(x.se != 2){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
