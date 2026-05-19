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
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    vector<vector<int>> posA(n+2), posB(n+2), com(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        posA[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        posB[b[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == b[i]){
            com[a[i]].push_back(i);
        }
    }
    // dp[p]: 假设两人在第 p 天完美同步看完了某一集
    // 他们未来第一次发生“行为不一致”的最小天数
    // 初始化为 n+1  
    vector<int> dp(n+2, n+1);
    // 从最后一集 n 倒推到第 1 集
    for(int x = n; x >= 1; x--){
        // 遍历所有两人在同一天(第 p 天)完美同步看了第 x 集的日子
        for(int &p: com[x]){
            int nxta = n+1;
            int nxtb = n+1;
            auto ita = upper_bound(posA[x+1].begin(), posA[x+1].end(), p);
            auto itb = upper_bound(posB[x+1].begin(), posB[x+1].end(), p);
            if(ita != posA[x+1].end()) nxta = *ita;
            if(itb != posB[x+1].end()) nxtb = *itb;
            if(nxta == nxtb){
                if(nxta == n+1){
                    dp[p] = n+1;
                }else{
                    dp[p] = dp[nxta];
                }
            }else{
                dp[p] = min(nxta , nxtb);
            }
        }
    }

    int ans = 0;
    for(int l = 1; l <= n; l++){
        int nxta = n+1;
        int nxtb = n+1;
        auto ita = lower_bound(posA[1].begin(), posA[1].end(), l);
        auto itb = lower_bound(posB[1].begin(), posB[1].end(), l);   
        if(ita != posA[1].end()) nxta = *ita;
        if(itb != posB[1].end()) nxtb = *itb;

        int r;
        if(nxta == nxtb){
            if(nxta == n+1){
                r = n+1;
            }else{
                r = dp[nxta];
            }
        }else{
            r = min(nxta, nxtb);
        }
        ans += r - l;
    }
    cout << ans << endl;
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