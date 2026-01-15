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
 *  题目名称：Tokens on the Segments (第十届山东省赛)
 *  
 *  本质是一个"区间贪心"或"资源分配"问题。
 *  资源：数轴上的整数坐标点 (now)。资源是稀缺的，每个坐标只能分给一个线段。
 *  冲突：当一个坐标同时被多个线段覆盖时，应该分配给谁？
 *  贪心策略：优先分配给"容错率最低"的线段。
 *  即：在所有当前能放的线段中，选择右端点 (R) 最小的那个。
 *  原因：R 越小，意味着如果不现在处理，它马上就过期作废了；而 R 大的线段以后还有机会。
 *
 *  
 *  排序 (Sort)：按左端点 L 从小到大排序。
 *  作用：模拟时间/坐标轴的流逝，有序地让线段"进场"。
 *  小根堆 (Min-Heap)：优先队列维护当前候选线段的右端点 R。
 *  作用：O(1) 时间取出当前最紧迫 (R 最小) 的任务。
 *
 * 
 *  维护一个坐标指针 now 和线段指针 idx。
 *  循环执行以下步骤：
 *  1.若堆空了且 now < 下个线段起点，直接瞬移 now = a[idx].L
 *  2.将所有已开始 (L <= now) 的线段加入堆 (只存 R)。
 *  3.若堆顶线段已过期 (R < now)，直接扔掉。
 *  4.取出堆顶 (R 最小)，ans++，now++ (消耗该坐标)。
 */
void solve(){
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin()+1,a.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    int ans = 0;
    int now = 0,i = 1; //i指：下一个还没进待办列表的任务的下标
    while(i <= n || !pq.empty()){
        if(pq.empty() && now < a[i].fi){
            now = a[i].fi;
        }
        while(i <= n && a[i].fi <= now){
            pq.push(a[i].se);
            i++;
        }
        while(!pq.empty() && pq.top() < now){
            pq.pop();
        }
        if(pq.size()){
            pq.pop();
            ans++;
            now++;
        }
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