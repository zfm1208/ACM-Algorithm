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
const int N = 5e5+7, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
// 字典树最长前缀查询
int tree[N][27];
int mark[N];
int idx = 0;
void insert(string s){
    int p = 0;
    for(int i = 0; i < s.size(); i++){
        int u = s[i]-'a';
        if(!tree[p][u]) tree[p][u] = ++idx; // 未出现加编号
        else mark[tree[p][u]]++; // 已经出现过了，mark标记下，表示有共同字符前缀
        p = tree[p][u];
    }
}
int find(string s){
    int p = 0;
    int cnt = 0; // 找最长公共前缀的长度
    for(int i = 0; i < s.size(); i++){
        int u = s[i]-'a';
        if(!mark[tree[p][u]]) break;
        else cnt++;
        p = tree[p][u];
    }
    return cnt;
}
void solve() {
    int n; cin >> n;
    vector<string> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        insert(a[i]);
    }
    for(int i = 1; i <= n; i++){
        cout << find(a[i]) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}