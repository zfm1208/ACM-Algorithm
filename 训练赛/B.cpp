#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(2 * n + 1);
    map<int, int> cntL;
    rep(i, 1, 2 * n) cin >> a[i];
    // 统计左半边的情况
    rep(i, 1, n) cntL[a[i]]++;
    
    vector<int> L2, L1, R2;
    for(int i = 1; i <= n; i++){
        if(cntL[i] == 2) L2.pb(i);
        else if(cntL[i] == 1) L1.pb(i);
        else R2.pb(i); 
    }
    vector<int> ansL, ansR;
    // 策略：优先拿成对的（异或为0），最后拿单个的（左右对称）
    // 每个人要拿 2k 个数
    int cnt = 0;
    // 先拿成对的
    for(int x : L2){
        if(cnt + 2 <= 2 * k){
            ansL.pb(x); ansL.pb(x);
            // 为了平衡，右边也拿一对（虽然数不同，但异或都是0）
            int y = R2.back(); R2.pop_back();
            ansR.pb(y); ansR.pb(y);
            cnt += 2;
        }else break;
    }
    // 剩下的空位用单个的填，左右拿一样的
    for(int x : L1){
        if(cnt < 2 * k){
            ansL.pb(x);
            ansR.pb(x);
            cnt++;
        }else break;
    }
    for(int x : ansL) cout << x << " "; cout << endl;
    for(int x : ansR) cout << x << " "; cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}