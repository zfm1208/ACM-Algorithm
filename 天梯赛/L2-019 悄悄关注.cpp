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
struct node {
    string id;
    int like;
};
void solve(){
    int n; cin >> n;
    unordered_set<string> ust;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        ust.insert(s);
    }
    int m; cin >> m;
    vector<node> us(m);
    int sum = 0;
    for(int i = 0; i < m; i++){
        cin >> us[i].id >> us[i].like;
        sum += us[i].like;
    }
    double av = sum * 1.0 / m;
    set<string> ans;
    for(int i = 0; i < m; i++){
        if(us[i].like > av && ust.count(us[i].id) == 0) {
            ans.insert(us[i].id);
        }
    }

    if (ans.empty()) {
        cout << "Bing Mei You\n";
    } else {
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            cout << *it << "\n";
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