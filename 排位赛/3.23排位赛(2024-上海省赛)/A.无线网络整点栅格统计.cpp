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

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> ans(n+1,vector<int>(m+1));
    for(int x = 0; x <= n; x++)
    {
        for(int y = 0; y <= m; y++)
        {
            ans[x][y] = min(x,y) + min(x,m-y) + min(n-x,y) + min(n-x,m-y);
            int sum = 0;
            // 上面
            int shang = min(x,m);
            for(int jie = 1; jie < shang; jie++) // 枚举几阶
            {
                for(int i = 1; i <= jie; i++){
                    int L = y - (jie + 1 - i);
                    int R = y + i;
                    if(L >= 0 && R <= m) sum++;
                }
            }
            // 下面
            int xia = min(n-x,m);
            for(int jie = 1; jie < xia; jie++) // 枚举几阶
            {
                for(int i = 1; i <= jie; i++){
                    int L = y - (jie + 1 - i);
                    int R = y + i;
                    if(L >= 0 && R <= m) sum++;
                }
            }
            // 左面
            int zuo = min(n,y);
            for(int jie = 1; jie < zuo; jie++) // 枚举几阶
            {
                for(int i = 1; i <= jie; i++){
                    int top = x - (jie + 1 - i);
                    int down = x + i;
                    if(top >= 0 && down <= n) sum++;
                }
            }
            // 右面
            int you = min(n,m-y);
            for(int jie = 1; jie < you; jie++) // 枚举几阶
            {
                for(int i = 1; i <= jie; i++){
                    int top = x - (jie + 1 - i);
                    int down = x + i;
                    if(top >= 0 && down <= n) sum++;
                }
            }
            ans[x][y] += sum;
        }   
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << ans[i][j] << " \n"[j==m];
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