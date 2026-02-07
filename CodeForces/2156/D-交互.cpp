// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve() {
    int n; cin >> n;
    int mx = 0; // n的最高位
    for(int i = 30; i >= 0; i--){
        if(n >> i & 1){
            mx = i;
            break;
        }
    }
    vector<vector<int>> f(mx + 1, vector<int> (2));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= mx; j++){
            f[j][i >> j & 1]++;
        }
    }
    vector<int> a;
    rep(i,1,n-1) a.push_back(i);
    auto b = a; // b: 候选答案数组
    b.push_back(n);
    vector<int> vis(n+1);

    auto ask = [&] (int i, int x) -> bool {
        cout << "? " << i << " " << x << endl;
        int ans; cin >> ans;
        return ans;
    };

    for(int i = 0; i <= mx && b.size() > 1; i++){
        vector<vector<int>> cun(2);
        for(auto &x : a){
            cun[ask(x, 1 << i)].push_back(x);
        }
        if(cun[0].size() < f[i][0]){ // P_n : 第 i 位为0
            a = cun[0];
            vector<int> temp;
            for(auto &x : b){
                if(x >> i & 1){
                    vis[x] = 1;
                    for(int j = i + 1; j <= mx; j++){
                        f[j][x >> j & 1]--;
                    }
                }else{
                    temp.push_back(x);
                }
            }
            b = temp;
        }else{ // P_n : 第 i 位为1
            a = cun[1];
            vector<int> temp;
            for(auto &x : b){
                if(x >> i & 1){
                    temp.push_back(x);
                }else{
                    vis[x] = 1;
                    for(int j = i + 1; j <= mx; j++){
                        f[j][x >> j & 1]--;
                    }                    
                }
            }
            b = temp;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << "! " << i << endl;
            return;
        }
    }

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}