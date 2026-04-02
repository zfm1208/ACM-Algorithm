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
double get(int x, int y, int x1, int y1){
    int xx = abs(x-x1);
    int yy = abs(y-y1);
    return sqrt(xx * xx + yy * yy);
}
/*
    这一题要求最短的距离，用最小堆是不对的
    原因是每个人只有一种路线
    但每个人有四种选择： 不去食堂，去1个/2个/3个
    我们要在这四种选择中选择最优的
    而如果把这四种结果全塞进堆里面，可能造成一个人多种路线
    并且你去x个食堂，收益也是*x的, 
    所以不能用优先队列-最小堆

    我们这时候我们要想一下？
    每个个体有多个选择，但只能选一个,且最后是为了凑成某个目标
    ! 应当想到 背包问题 DP

    我们最后要进入食堂 need 次, 如何安排人手呢？
    一共k个人, 
    每个人 可能有三种选择，对应物品的三种属性

    限制: 每个同学最多只能被选一次

    ! 分组背包求最小值

    状态定于  dp[i] : 目前已经去了i次食堂,所花费的最小总距离
    转台转移  我们一个接一个观察每个同学, 对于当前同学
    如果不去，状态不变；
    如果去，他可以把旧状态 dp[j] 推进到新状态 dp[j+1]、dp[j+2] 或 dp[j+3] 
    用min来更新状态
    
    tip: dp[0] = 0 (别忘初始化)
*/
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int b,e;cin >> b >> e;
    vector<pii> st;
    for(int i = 1; i <= 3; i++){
        int x,y; cin >> x >> y;
        st.pb({x,y});
    }
    int sx,sy; cin >> sx >> sy;
    vector<pii> xs;
    for(int i = 1; i <= k; i++){
        int x,y; cin >> x >> y;
        xs.pb({x,y});
    }
    double ans = 0;
    int need = max((n+b-1)/b,(m+e-1)/e);
    // priority_queue<double,vector<double>,greater<double>> pq;
    // dp[i] : 表示到达i次食堂访问的最短总距离
    vector<double> dp(need+1,inf); 
    dp[0] = 0;
    for(auto [x,y] : xs)
    {
        double dist1 = inf;
        for(auto [x1,y1]: st){
            double d1 = get(x,y,x1,y1);
            double d2 = get(x1,y1,sx,sy);
            dist1 = min(dist1, d1 + d2);
        }
        // pq.push(dist);

        double dist2 = inf;
        for(int i = 0; i < 3; i++)
        {
            auto [x1,y1] = st[i];
            for(int j = 0; j < 3; j++)
            {
                if(i != j)
                {
                    auto [x2,y2] = st[j];
                    double d1 = get(x,y,x1,y1);
                    double d2 = get(x1,y1,x2,y2);
                    double d3 = get(x2,y2,sx,sy);
                    dist2 = min(dist2, d1 + d2 + d3);
                }
            }
        }
        // pq.push(dist);

        double dist3 = inf;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i != j) for(int q = 0; q < 3; q++) if(q != i && q != j)               
                {
                    auto [x1,y1] = st[i];
                    auto [x2,y2] = st[j];
                    auto [x3,y3] = st[q];
                    double d1 = get(x,y,x1,y1);
                    double d2 = get(x1,y1,x2,y2);
                    double d3 = get(x2,y2,x3,y3);
                    double d4 = get(x3,y3,sx,sy);
                    dist3 = min(dist3, d1 + d2 + d3 + d4);
                }
            }
        }
        // pq.push(dist);
        vector<double> ndp = dp;
        for(int i = 0; i <= need; i++){
            if(dp[i] == inf) continue;
            ndp[min(i+1,need)] = min(ndp[min(i+1,need)], dp[i] + dist1);
            ndp[min(i+2,need)] = min(ndp[min(i+2,need)], dp[i] + dist2);
            ndp[min(i+3,need)] = min(ndp[min(i+3,need)], dp[i] + dist3);
        }
        dp = ndp;
    }
    ans = dp[need];
    cout << fixed << setprecision(10) << ans << endl;

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