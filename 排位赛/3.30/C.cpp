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
    赛时没过

    正常的会场安排问题,时间是自己流逝的,时间会直接推进到下一个会议开始

    但这道题 时间是 当前参加游戏的人数cnt, 只有当成功拉了一个人之后,才会+1

    ! 思路
    既然不能简单排序一遍过,我们就要大胆换思路
    <1>: 当前有cnt个人, 那么满足 L <= cnt 的人, 现在或以后都有机会参加
    所以我们可以按照L 从小到大排序
    随着cnt 的增加 我们把越来越多 满足L <= cnt 的人放进候选里面

    <2>: 贪心策略在于, 在候选池里面优选快'过期'的人，
    也就是选在候选池里面 r 最小的人

    <3>: 如果候选池有人 r < cnt,说明这个人被pass了, 踢出即可

*/
void solve(){
    int n; cin >> n;
    vector<array<int,3>> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin()+1,a.end());
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> ans;
    int cnt = 0;
    int idx = 1;
    while(1){
        while(idx <= n && a[idx][0] <= cnt){
            pq.push({a[idx][1], a[idx][2]});
            idx++;
        }
        while(!pq.empty() && pq.top().fi < cnt) pq.pop();
        if(pq.empty()) break;
        ans.pb(pq.top().se);
        pq.pop();
        cnt++;
    }
    cout << cnt << endl;
    for(int x: ans) cout << x << " ";
    cout << endl;

    // int n; cin >> n;
    // vector<array<int,3>> a(n+1);
    // rep(i,1,n) {
    //     int x,y; cin >> x >> y;
    //     a[i] = {x,y,i};
    // }
    // sort(a.begin()+1,a.end(),[](auto x, auto y){
    //     if(x[1] == y[1]) return x[0] < y[0];
    //     return x[1] < y[1];
    // });
    // int cnt = 0;
    // vector<int> ans;
    // for(int i = 1; i <= n; i++){
    //     if(a[i][0] <= cnt && cnt <= a[i][1]){
    //         cnt++;
    //         ans.pb(a[i][2]);
    //     } 
    // }
    // cout << cnt << endl;
    // for(auto x: ans) cout << x << " ";
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