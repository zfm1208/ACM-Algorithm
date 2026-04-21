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
const int N = 1e6+3, mod = 1e9+7, inf = 1e18 + 5;
int nxt[N][26];
int cnt[N];
int a[26][26];
int id = 0;
int res = 0;
void insert(const string& s){
    int p = 0;
    for(int i = 0; i < (int)s.size(); i++){
        int x = s[i] - 'a';
        for(int j = 0; j < 26; j++){
            if(x != j && nxt[p][j] != 0){
                a[x][j] += cnt[nxt[p][j]];
            }
        }
        if(nxt[p][x] == 0) nxt[p][x] = ++id;
        p = nxt[p][x];
        cnt[p]++;
    }
    for(int i = 0; i < 26; i++){
        if(nxt[p][i] != 0){
            res += cnt[nxt[p][i]];
        }
    }
}
void solve(){
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    while(q--){
        string s; 
        cin >> s;
        int ans = res;
        for(int i = 0; i < 26; i++){
            for(int j = i+1; j < 26; j++){
                int x = s[i] - 'a';
                int y = s[j] - 'a';
                if(a[x][y]) ans += a[x][y];
            }
        }
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