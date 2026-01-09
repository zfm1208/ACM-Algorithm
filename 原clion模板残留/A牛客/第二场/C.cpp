//https://ac.nowcoder.com/acm/contest/95334/C
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
//题解解法
//void solve() {
//    int n, m;
//    cin >> n >> m;
//    if (n == m || n - m > 26) {
//        cout << "NO\n";
//        return;
//    }
//    cout << "YES\n";
//    for (int i = 0; i < n; i++) {
//        cout << (char)('a' + i % (n - m));
//    }
//    cout << "\n";
//}、
void solve() {
    int n, m;
    cin >> n >> m;
    if(m >= n || n - m > 26){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        string s;
        string s1;
        char t = 'a';
        int p = n - m;
        for(int i = 0; i < p; i++){
            char d = t + i;
            s1 += d;
        }
//        cout << s1 << endl;
        char c[n+1];
        int cnt = p - 1;
        for(int i = m; i >= 1; i--){
            c[i] = s1[cnt];
            cnt--;
            if(cnt < 0) cnt = p - 1;
        }
        for(int i = 1; i <= m; i++){
            s += c[i];
        }
        s += s1;
        cout << s << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
