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
const int N = 1e6 + 10, mod = 1e9+7, inf = 1e18 + 5;
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
    线性基：
    作用：给你一堆数，你可以从里面随便选一些数进行XOR，问你能得到的最大值
    性质：
    1> 线性基里的数可以异或出 原数组里面的每个数
    2> 线性基里的数有最简性
    3> 因为最简，所有可以贪心就最大值
    核心：
    insert : 把一个数扔进线性基，能被现有基拼出来就忽略;否则加进去
    query_max : 从高位到低位扫描，如果异或上当前的基能让结果变大，就异或它
*/

// 线性基模板类
struct LinearBasis{
    int p[64]; // p[i] 存储的是一个二进制最高位是第i位的数字
    bool zero; // 是否能异或出0,用来标记是否出现了 完全被消掉 的情况
    void init(){
        memset(p, 0, sizeof(p));
        zero = false;
    }

    void insert(int x){
        for(int i = 62; i >= 0; i--){
            if(!(x >> i & 1)) continue; 
            if(!p[i]){ 
                p[i] = x;
                return;
            }
            x ^= p[i]; 
        }
        zero = true; 
    }
    // 查询能构成的最大异或和
    int query_max(){
        int res = 0;
        for(int i = 62; i >= 0; i--){
            // 如果异或上这个基底能让结果变大，就异或
            if((res ^ p[i]) > res){
                res ^= p[i];
            }
        }
        return res;
    }
}LB;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    if(n%4 != 2 || n == 2){
        LB.init();
        // 构造a[1] ^ a[i]
        for(int i = 2; i <= n; i++){
            LB.insert(a[1] ^ a[i]);
        }
        cout << LB.query_max() << endl;
    }else if(n%4 == 2 && n != 2){
        int ans = 0;
        // 枚举更新哪个数扔掉后得到的答案最大
        for(int i = 2; i <= n; i++){ 
            LB.init();
            for(int j = 2; j <= n; j++){
                if(i == j) continue;
                LB.insert(a[1] ^ a[j]);
            }
            ans = max(ans,LB.query_max());
        }
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
【线性基详解 -  CSDN App】https://blog.csdn.net/a_forever_dream/article/details/83654397?sharetype=blogdetail&shareId=83654397&sharerefer=APP&sharesource=2403_86967165&sharefrom=link
*/