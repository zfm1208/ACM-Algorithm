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
const int N = 1e6, mod = 998244353, inf = 1e18 + 5;
struct Matrix{
    int mat[4][4]; // 3*3矩阵
    Matrix(){
        memset(mat,0,sizeof(mat));
    }
    //重载乘法运算符, "Matrix A * Matrix B" 到底该怎么算
    Matrix operator * (const Matrix &b) const {
        Matrix res;
        // 标准的矩阵乘法循环：行(i) * 列(j)
        for(int i = 1; i <= 3; i++){
            for(int k = 1; k <= 3; k++){
                if(mat[i][k]){
                    for(int j = 1; j <= 3; j++){
                        // C[i][j] += A[i][k] * B[k][j]
                        res.mat[i][j] = (res.mat[i][j] + mat[i][k] * b.mat[k][j]) % mod;
                    }
                }
            }
        }
        return res;
    };
};
// 矩阵快速幂
Matrix power(Matrix a, int b){
    Matrix res;
    // 单位矩阵，主对角线=1
    for(int i = 1; i <= 3; i++) res.mat[i][i] = 1;
    while(b){
        if(b&1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int n,m;
int pos[N];
int p[N];
int a[N]; // 看这个数对于k来说是大数还是小数
int cnt[4];
// cnt[1]: 00对的数量
// cnt[2]: 11对的数量
// cnt[3]: 01/10对的数量


void change (int i, int x){
    if(i < n && i >= 1){
        int u = a[i],v = a[i+1];
        if(u == 0 && v == 0) cnt[1] += x;
        else if(u == 1 && v == 1) cnt[2] += x;
        else cnt[3] += x;
    }
    if(i > 1){
        int u = a[i - 1],v = a[i];     
        if(u == 0 && v == 0) cnt[1] += x;
        else if(u == 1 && v == 1) cnt[2] += x;
        else cnt[3] += x;
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        pos[p[i]] = i;
        a[i] = 1;
    }
    // 初始k=0
    cnt[1] = 0; 
    cnt[2] = n-1;
    cnt[3] = 0;
    // C(n-2,2)
    int rest = (n - 2) * (n - 3) / 2 % mod;
    int ans = 0;
    for(int k = 1; k <= n-1; k++){
        int i = pos[k];
        change(i,-1);
        a[i] = 0;
        change(i,1);
        int c0 = k,c1 = n-k;
        Matrix T;
        // [第1列] 从 00 转移而来 
        T.mat[1][1] = ((rest + 1 + 2 * (c0 - 2)) % mod + mod) % mod;
        T.mat[3][1] = 2 * c1 % mod; 
        T.mat[2][1] = 0; 
        // [第2列] 从 11 转移而来
        T.mat[2][2] = ((rest + 1 + 2 * (c1 - 2)) % mod + mod) % mod;
        T.mat[3][2] = 2 * c0 % mod;
        T.mat[1][2] = 0; 
        // [第3列] 从 Mix 转移而来  
        T.mat[1][3] = c0 - 1;
        T.mat[2][3] = c1 - 1;
        T.mat[3][3] = (rest + 1 + (c0 - 1) + (c1 - 1)) % mod;
        // 矩阵加速
        Matrix T1 = power(T,m);

        int mix = T1.mat[3][1] * cnt[1] % mod + T1.mat[3][2] % mod * cnt[2] % mod + T1.mat[3][3] % mod * cnt[3] % mod;
        ans = (ans + mix) % mod;
    }
    cout << ans << endl;
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