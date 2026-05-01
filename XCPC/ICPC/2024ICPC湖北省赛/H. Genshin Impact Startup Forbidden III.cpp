#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

// 曼哈顿距离的四个方向，加上原地(0, 0)
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;
    
    // 采用 0-based 索引 (0 到 k-1)，完美契合位运算的偏移量
    vector<pii> fish(k); 
    vector<int> cnt(k);  
    for(int i = 0; i < k; i++){
        cin >> fish[i].first >> fish[i].second >> cnt[i];
    }

    // 1. 寻找有意义的炸弹落点
    set<pii> st1;
    for(int i = 0; i < k; i++){
        for(int d = 0; d < 5; d++){
            auto [x, y] = fish[i];
            int nx = x + dx[d];
            int ny = y + dy[d];
            // 确保落点不越出网格边界
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                st1.insert({nx, ny});
            }
        }
    }

    // 2. 将每个落点转化为“杀伤掩码 (Mask)”
    vector<int> bombs;
    for(auto [x, y] : st1){
        int mask = 0;
        for(int i = 0; i < k; i++){
            auto [x1, y1] = fish[i];
            // 曼哈顿距离 <= 1 则被覆盖
            if(abs(x - x1) + abs(y - y1) <= 1){
                mask |= (1 << i); // 记录该炸弹能炸到第 i 号格子
            }
        }
        if(mask > 0) {
            bombs.push_back(mask);
        }
    }
    
    // 3. 去重优化：剔除覆盖范围完全相同的冗余炸弹
    sort(bombs.begin(), bombs.end());
    bombs.erase(unique(bombs.begin(), bombs.end()), bombs.end());

    // 4. 起点状态打包 (把 K 个格子的鱼，压缩进一个 Int 中)
    int st = 0; 
    for(int i = 0; i < k; i++){
        // cnt[i] 占用 2 个 bit，所以左移 2*i 位
        st |= (cnt[i] << (2 * i)); 
    }
    
    // dist 数组记录到达每个状态的最少步数
    // 最大状态空间为 4^k，即 1 << (2 * k)
    vector<int> dist(1LL << (2 * k), -1);
    dist[st] = 0;
    
    queue<int> q;
    q.push(st);
    
    // 5. 开始 BFS 走迷宫
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        // 走到终点：状态变为 0，所有鱼都清空了
        if(cur == 0){
            cout << dist[0] << endl;
            return; 
        }
        
        // 尝试投掷每一颗优质炸弹
        for(int mask : bombs){
            int nxt = cur; // 投掷后的新状态
            
            for(int i = 0; i < k; i++) {
                // 如果这颗炸弹能炸到第 i 号格子
                if((mask >> i) & 1) {
                    // 读取：把第 i 个 2-bit 隔间推到最右边，与 3 (二进制 11) 进行按位与，提取鱼的数量
                    int count = (nxt >> (2 * i)) & 3; 
                    
                    if(count > 0) {
                        // 修改：鱼死掉一条，整个状态减去该位置的基础权重 1 << (2 * i)
                        nxt -= (1 << (2 * i));
                    }
                }
            }
            
            // 如果这个新状态尚未到达过，入队并记录步数
            if(dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T; // 本题无多组测试数据，如有需解开注释
    while(T--)
        solve();
    return 0;
}