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
vector<int> pw(20);
void init(){
    pw[0] = 1;
    rep(i,1,18) pw[i] = pw[i-1] * 10;    
}
void solve(){
    int k; cin >> k;
    int ans = 0;

    for(int d = 1;; d++){
        //  d = 2; 100-10 = 90
        //  2*90 = 180 (总字符数)
        int count = pw[d] - pw[d-1];
        int len = d * count;
        if(len <= k){
            int gaowei = count * 5;
            int sywei = (d-1) * count / 2 * 9;
            int sum = gaowei + sywei;
            k -= len;
            ans += sum;
        }else{
            int pre = 0;
            vector<int> a;
            // 从高位开始遍历
            for(int i = 0; i < d; i++){
                int nowwei = pw[d-i-1];
                int cnt = k/d; //把字符数换算成多少个完整的数字
                int c = cnt / nowwei; //c 是算出当前位经历了多少个完整的 0-9 循环
                ans += pre * c * nowwei;
                int d1 = c * (c + 1) / 2;
                int d2 = c * (c - 1) / 2;
                int sum = (i == 0 ? d1 : d2);
                ans += sum * nowwei;
                ans += c * nowwei * (d - 1 - i) / 2 * 9;
                a.pb(c + (i == 0));
                pre += c + (i == 0);
                // 更新k
                k -= c * d * nowwei;
            }
            for(int i = 0; i < k; i++){
                ans += a[i];
            }
            break;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}