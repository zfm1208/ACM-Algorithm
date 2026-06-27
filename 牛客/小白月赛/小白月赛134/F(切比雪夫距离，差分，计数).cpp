#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
/*
    n,m 2000
    a[i][j] = max(|x - i|, |y - j|)
    就是点(i,j)到点(x,y)的切比雪夫距离
    如果固定中心 (x,y)，距离为k的点分布在一个以(x,y)为中心、半径k的正方形边框上
*/
void solve(){
    int n, m; cin >> n >> m;
    vector<vii> s(n + 3, vii(m + 3, 0));
    auto add = [&](int x1, int y1, int x2, int y2) -> void {
        x1 = max(x1, 1LL);
        y1 = max(y1, 1LL);
        x2 = min(x2, n);
        y2 = min(y2, m);
        if (x1 > x2 || y1 > y2) return;
        s[x1][y1]++;
        s[x2 + 1][y1]--;
        s[x1][y2 + 1]--;
        s[x2 + 1][y2 + 1]++;
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            if (x == 0){
                add(i, j, i, j);
            }else{
                add(i - x, j - x, i - x, j + x);
                add(i + x, j - x, i + x, j + x);
                add(i - x + 1, j - x, i + x - 1, j - x);
                add(i - x + 1, j + x, i + x - 1, j + x);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            ans = max(ans, s[i][j]);
        }
    }
    cout << n * m - ans << endl;
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