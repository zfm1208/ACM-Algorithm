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
    vector<vector<int>> st(n + 1); 
    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        while(m--){
            int x; cin >> x;
            st[i].push_back(x);
        }
        sort(st[i].begin(), st[i].end());
        st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end());
    }
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        int cnt = 0;
        int i = 0, j = 0;
        // 两个数组都是有序的，查找相同元素个数，双指针遍历
        while(i < st[a].size() && j < st[b].size()){
            if(st[a][i] == st[b][j]){
                cnt++;
                i++;
                j++;
            } else if(st[a][i] < st[b][j]){
                i++;
            } else {
                j++;
            }
        }
        int tot = st[a].size() + st[b].size() - cnt; 
        double ans = cnt * 100.0 / tot;
        cout << fixed << setprecision(2) << ans << "%" << '\n';        
    }
}
// void solve(){
//     int n; cin >> n;
//     // map<int,set<int>> mp;
//     // 优化 -- 用 vector 代替 map
//     // vector<set<int>> mp(n + 1); 
//     // 用unordered_set 再次优化
//     vector<unordered_set<int>> mp(n + 1);
//     for(int i = 1; i <= n; i++){
//         int m; cin >> m;
//         while(m--){
//             int x; cin >> x;
//             mp[i].insert(x);
//         }
//     }
//     int q; cin >>q;
//     while(q--){
//         int a,b; cin >> a >> b;
//         double ans;
//         int cnt = 0;
//         // set<int> tp = mp[b];
//         for(auto &x: mp[a]){
//             if(mp[b].find(x) != mp[b].end()){
//                 cnt++;
//             }
//             else{
//                 // tp.insert(x);
//             }
//         }
//         // int tot = tp.size();
//         // 根据容斥原理 - 优化
//         int tot = mp[a].size() + mp[b].size() - cnt;
//         ans = cnt * 100.0 / tot;
//         cout << fixed << setprecision(2) << ans << "%" << endl;        
//     }
// }

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}