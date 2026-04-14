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
    直接排序？谁背谁？背了之后速度够不够？
    问题：“求整个队伍能达到的最大速度。” 
    而队伍的速度定义为：所有未被背负的队员中，最慢的队员的速度。
    最大化最小值 -> 二分答案
    直接检验某个速度V可不可以
    对于初始速度 v1 < V的人 必须被人背
    对于初始速度 v2 >= k的人 可以自己走也可以背别人

    若 i 背 j ，若wi < wj
    vi - (wj - wi) >= V
    wj <= vi + wi - V

    开两个数组去存这两类人的体重/最大携带重量，然后比较能否合理分配完
*/
void solve(){
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    auto check = [&] (int V) -> bool {
        vector<int> hao,huai;
        for(int i = 1; i <= n; i++){
            if(a[i].fi < V){
                huai.pb(a[i].se);
            }else{
                hao.pb(a[i].fi + a[i].se - V);
            }
        }
        if(huai.size() > hao.size()) return false;
        sort(hao.begin(),hao.end());
        sort(huai.begin(),huai.end());
        int l = 0,r = 0;
        while(l < hao.size() && r < huai.size()){
            if(hao[l] >= huai[r]){
                l++;
                r++;
            }else{
                l++;
            }
        }
        return r == huai.size();
    };
    int l = 0,r = 1e9;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
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