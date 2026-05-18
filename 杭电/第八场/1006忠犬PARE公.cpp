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
const int N = 1e6+5, mod = 1e9+7, inf = 1e18 + 5;
/*
    sum of (lcm(ai, bj) / gcd(ai,bj))  
    i (1 ~ n of a[])     j(1 ~ m of b[])

*/
int A[N], B[N];
int SA[N], SB[N];
int mu[N], pri[N];
int cnt;
int vis[N];
int g[N]; //  g[T] = sum of [(k | T) mu[k] * k * k];
// 线性求莫比乌斯反演函数
void init(){
    mu[1] = 1;
    // 欧拉筛求: 莫比乌斯反演函数 mu[i]
    for(int i = 2; i < N; i++){
        if(vis[i] == 0){
            pri[++cnt] = i;
            mu[i] = -1;
        }
        for(int j = 1; pri[j] * i < N; j++){
            vis[pri[j] * i] = 1;
            if(i % pri[j] == 0){
                mu[pri[j] * i] = 0;
                break;
            }
            mu[pri[j] * i] = -mu[i];
        }
    }
    // 调和级数求和 O(N ln N) 
    // 求 g[T] = sum of [(k | T) mu[k] * k * k];
    for(int k = 1; k < N; k++){
        if(mu[k] == 0) continue;
        int tp = (mu[k] * (k * k % mod) % mod + mod) % mod;
        for(int T = k; T < N; T += k){
            g[T] = (g[T] + tp) % mod;
        }
    }
}
void solve(){
    int n,m; cin >> n >> m;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        A[x]++;
        mx = max(mx, x);
    }
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        B[x]++;
        mx = max(mx, x);
    }

    for(int T = 1; T <= mx; T++){
        int sumA = 0, sumB = 0;
        for(int u = 1; T * u <= mx; u++){
            if(A[T * u]) sumA = (sumA + A[T * u] * u) % mod;
            if(B[T * u]) sumB = (sumB + B[T * u] * u) % mod;
        }
        SA[T] = sumA;
        SB[T] = sumB;
    }
    int ans = 0;
    for(int T = 1; T <= mx; T++){
        if(!SA[T] || !SB[T]) continue; 
        int cur = SA[T] * SB[T] % mod;
        cur = cur * g[T] % mod;
        ans = (ans + cur) % mod;
    }
    cout << ans << endl;
    for(int i = 1; i <= mx; i++){
        A[i] = B[i] = SA[i] = SB[i] = 0;
    }
    
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