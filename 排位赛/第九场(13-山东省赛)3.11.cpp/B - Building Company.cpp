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
/*
    有g种员工，编号为t[i],该类员工有u[i]人
    有n个项目
    第i个必须满足m[i]个条件
    第j个条件是 要有 b[i][j]个a[i][j]员工
    第i个项目完成,会吸引k[i]种类型的员工
    第j种员工职业为c[i][j]，共d[i][j]人
    项目不会使员工减少
    求最多承接项目的数量
*/


/*
    一开始是用的N*N的暴力,每次只要有任何新成员的加入，就会把所有没完成的任务从头到尾扫一遍
    这样肯定超时,不难发现,我们应该只在某个职业的员工数量发生变化时,去检查刚好缺这个职业的项目

    从项目找人 -> 人找项目

    如果判断这个项目可以完成呢？ 当这个项目所有条件都完成时。
    vector<int> rem(n+1);
    rem[i]: 这个项目还剩多少条件需要完成
    一旦 rem[i] = 0,就说明这个项目可以做了

    如何解决谁在等这个职业？ 用临界表去存
    map<int,vector<pii>> wait;
    因为职业编号最大1e9,所以我们用map<int,...>
    一个职业可能需要多个项目需要,vector去存
    我们需要知道需要多少人,哪个项目需要, pii 去存

    如果解决无脑通知的浪费? 排序和尾部弹出

    假如有多个项目都需要同一个员工, 我们肯定是要先满足项目需求小的
    sort排序 + pop_back弹出
    我们后面check时,满足就 弹出

    我们用队列bfs遍历
    queue<int> pq;

    只要rem[id] = 0,那就丢进队列里面,在用一个vis数组去维护防止重复
    
*/
void solve(){
    int g; cin >> g;
    map<int,int> mp;
    vector<int> t(g+1),u(g+1);
    for(int i = 1; i <= g; i++){
        cin >> t[i] >> u[i];
        mp[t[i]] += u[i];
    }
    int n; cin >> n;
    vector<vector<int>> a(n+1),b(n+1),c(n+1),d(n+1);
    vector<int> rem(n+1);
    map<int,vector<pii>> wait; // wait[职业] ={{需要人数，项目id}.. }
    vector<vector<pii>> jl(n+1);
    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        a[i].resize(m+1);
        b[i].resize(m+1);
        rem[i] = m;
        for(int j = 1; j <= m; j++){
            cin >> a[i][j] >> b[i][j];
            if(mp.count(a[i][j]) & mp[a[i][j]] >= b[i][j]){
                rem[i]--;
            }else{
                wait[a[i][j]].pb({b[i][j],i});
            }
        }
        int k; cin >> k;
        c[i].resize(k+1);
        d[i].resize(k+1);
        for(int j = 1; j <= k; j++){
            cin >> c[i][j] >> d[i][j];
            jl[i].pb({c[i][j],d[i][j]});
        }
    }
    int ans = 0;
    for(auto &[x,arr]: wait){
        sort(arr.begin(),arr.end(),greater<pii>());
    }
    queue<int> pq;
    rep(i,1,n) if(!rem[i]) pq.push(i);
    vector<int> vis(n+1);
    while(pq.size()){
        int cur = pq.front();
        pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        ans++;
        for(auto &[c,d] : jl[cur]){
            mp[c] += d;
            while(!wait[c].empty()){
                auto[x,id] = wait[c].back();
                if(x > mp[c]) break;
                wait[c].pop_back();
                rem[id]--;
                if(rem[id] == 0) pq.push(id);
            }
        }
    }
    cout << ans << endl;
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