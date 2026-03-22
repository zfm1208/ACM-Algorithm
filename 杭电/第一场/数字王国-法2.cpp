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
    首先 n >= k 一定无解
    然后题意是 任何一段连续的数都不能被k整除

    连续的字串 - 前缀和
    [l,r] : pre[r] - pre[l-1]
    (pre[r] - pre[l-1]) % k != 0
    pre[r] % k !=  pre[l-1] % k
    也就是要保证 所有前缀和对k取模 的余数互不相同
    同样不能是k的倍数 所有取模后不能是0
    我们开一个mp,来标记维护取余后的余数
    然后怎么找严格递增字典序最小的呢？ 
    详见代码
*/
void solve(){
    int n,k; cin >> n >> k;
    if(n >= k){
        cout << -1 << endl;
        return;
    }
    int now = 1;
    int sum = 0;
    map<int,int> mp;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        while(mp.count((sum + now) % k)){
            now++;
        }
        cout << now << " ";
        sum = (sum + now) % k;
        mp[sum] = 1;
        now++;
    }
    cout << endl;
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