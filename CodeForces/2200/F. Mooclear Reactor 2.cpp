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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
/*
    手里有n个粒子，每个粒子有2个属性,x,y
    x : 粒子的能量
    y ：粒子的容忍度
    商店有m个粒子,问:每个粒子所能产生的最大能量是多少(该粒子可选可不选)

    如果要挑k个粒子组成一个团队,一个粒子的容忍度意味着：
    在一个团队中接受除了它之外最多还有y个粒子
    说明这个团队的每一个粒子的容忍度必须满足: y >= k-1
    那我们怎么高效的去处理呢,有m次询问,我们可以去预处理
    我们先跑出来这n个粒子所能产生的最大的能量

    然后我们再好好去想一下这个关系
    如果团队的人k越多, 那么对于y的下限就越严格,满足的粒子就越少
    团队的人k越少, 那么对于y的下限就越宽松,满足的粒子就越多
    我们当然是想要更多的粒子,然后选能量做多的那些

    根据前面推断的,我们试着去想,正向枚举团队人数siz,我们会面临这踢出一些粒子
    我们倒过来考虑下，从大到小枚举siz
    随着枚举我们发现，之前满足的粒子现在依旧满足，
    对于池子里已经选的粒子,如果超过了siz，我们要弹出来能量最小的那几个
    我们可以用优先队列(小根堆)维护
    
    这样一直枚举,我们预处理出来这n个粒子本身的最大能量
    和 g[siz] : 当前团队最多siz+1的人所能支持的最大能量
    以便后续m次询问时高效回答
*/
void solve(){   
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n+2);
    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;
        a[y].pb(x);
    }
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    int sum = 0;
    vector<int> g(n+2);
    for(int siz = n+1; siz >= 1; siz--){
        for(int x: a[siz-1]){
            sum += x;
            pq.push(x);
        }
        while(pq.size() > siz){
            sum -= pq.top();
            pq.pop();
        }
        ans = max(ans, sum);
        if(pq.size() == siz){
            g[siz-1] = sum - pq.top();
        }else g[siz-1] = sum;
    }
    for(int i = 1; i <= n; i++){
        g[i] = max(g[i], g[i-1]);
    }
    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;
        int res = max(ans, g[y] + x);
        cout << res << " \n"[i==m];
    }
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