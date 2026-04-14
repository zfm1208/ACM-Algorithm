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
// https://codeforces.com/gym/106252/problem/B
/*
    题意：
    有一个 n*m 的画布，初始为空。你可以执行三种操作：
    1. 免费新建一个图层，可以填满同一种颜色，或者全透明。
    2. 花费 a 用画笔将任意图层的某一个像素改成任意颜色。
    3. 花费 b 用橡皮擦将任意图层的某一个像素变透明。
    图层从下往上叠加，最终显示的颜色是最顶层非透明的颜色。0表示透明。
    求画出给定目标图层的最小代价。
    
    思路 (贪心 + 增量计算)：
    1. 核心矛盾：新建纯色图层免费，但如果要在这个图层显示它下面的颜色，必须用橡皮擦穿透它（代价 b）。
       如果要显示透明(0)，必须把该位置的所有图层都擦穿。
    2. 贪心策略：由于越靠近顶部的纯色图层，需要被擦穿的代价越小。
       因此，我们应该按照目标颜色出现的频次从大到小，依次作为各层纯色图层（出现次数最多的放最上面）。
    3. 状态转移：假设我们建了 k 层纯色图层。
       - 从 k-1 层转移到 k 层时，第 k 频次的颜色不需要再用画笔（节省 color[i-1] * a）。
       - 但为了看到第 k 层，必须凿穿上面 k-1 层（增加 color[i-1] * (k-1) * b）。
       - 同时，所有目标为透明(0)的像素，都要多凿穿一层（增加 cnt_0 * b）。
    4. 剪枝：如果凿穿的代价 (k-1)*b >= a，说明还不如直接在顶层用画笔涂，此时再建新图层只会增加成本，直接 break。
*/
void solve(){
    int n,m,a,b; 
    cin >> n >> m >> a >> b;
    vector<vector<int>> p(n+1,vector<int>(m+1));
    unordered_map<int,int> mp;
    int cnt_0 = 0;
    rep(i,1,n) rep(j,1,m) {
        cin >> p[i][j];
        if(p[i][j] == 0) cnt_0++;
        else mp[p[i][j]]++;
    }
    vector<int> color;
    for(auto&[x,cnt]: mp){
        color.push_back(cnt);
    }
    sort(color.begin(),color.end(),greater<int>());
    int cost = a * (n * m  - cnt_0);
    int ans = cost;
    for(int i = 1; i <= color.size(); i++){
        int cost1 = (i-1) * b;
        if(cost1 >= a) break;
        // i-1 是因为color数组是0-base
        cost = cost - color[i-1] * a + color[i-1] * cost1 + cnt_0 * b;
        ans = min(ans, cost);
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