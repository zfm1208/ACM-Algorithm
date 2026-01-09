//赛后补的
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
void solve()
{
    int n; cin >> n;
    vector<string> a(n+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    vector<int> b(n+1),ans(n+1),c(n+1);
    for(int i = 1; i <= n; i ++)
        b[i] = n-i+1;
    for(int i = 1; i <= n; i ++){
        int cnt = 0;
        for(int j = i+1; j <= n; j ++){
            if(a[i][j] == '1'){
                c[j]++;
                cnt++;
            }
        }
        c[i] -= cnt;
    }
    for(int i = 1; i <= n; i ++){
        ans[i+c[b[i]]] = b[i];
    }
    for(int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}

//题解：
//#include <bits/stdc++.h>
//using namespace std;
//void solve() {
//    int n;
//    cin >> n;
//    vector<string> g(n);
//    for(auto &i : g) {
//        cin >> i;
//    }
//    vector<int> p(n);
//    iota(p.begin(), p.end(), 0);
//    sort(p.begin(), p.end(),
//         [&](int x, int y) {
//             if(g[x][y] == '1') return x < y;
//             else return x > y;
//         });
//    for(auto i : p) cout << i + 1 << " "; cout << '\n';
//}
//signed main() {
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    int ttt = 1;
//    cin >> ttt;
//    while(ttt--) {
//        solve();
//    }
//}