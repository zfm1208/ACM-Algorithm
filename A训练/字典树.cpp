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
const int N = 3e6, mod = 1e9+7, inf = 1e18 + 5;
// https://www.luogu.com.cn/problem/P8306

struct Tire {
    int nxt[N][65];
    int cnt[N];
    int id = 0;
    void init() {
        id = 0;
        memset(nxt[0], 0, sizeof(nxt[0]));
        cnt[0] = 0;
    }
    int getid(char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
        if (c >= '0' && c <= '9') return c - '0' + 52;
    }
    // 插入字符串s到字典树中
    void insert(const string& s) {
        int p = 0;
        for (auto c : s) {
            int x = getid(c);
            if (!nxt[p][x]) {
                nxt[p][x] = ++id;
                memset(nxt[id], 0, sizeof(nxt[id]));
                cnt[id] = 0;
            }
            p = nxt[p][x];
            cnt[p]++;
        }
        
    }

    // 查询字符串s是否存在于字典树中
    bool find(const string& s) {
        int p = 0;
        for (auto c : s) {

            int x = getid(c);
            if (!nxt[p][x]) return false;
            p = nxt[p][x];
        }
        return cnt[p] > 0;
    }
    int query(const string& s) {
        int p = 0;
        for (auto c : s) {
            int x = getid(c);
            if (!nxt[p][x]) return 0;
            p = nxt[p][x];
        }
        return cnt[p];
    }
};
Tire tire;
void solve(){
    int n,q; cin >> n >> q;
    tire.init();
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        tire.insert(s);
    }    
    while(q--) {
        string s; cin >> s;
        cout << tire.query(s) << endl;
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