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

void solve(){
    int n,m; cin >> n >> m;
    if(m == 1){
        cout << 0 << endl;
        return;
    }
    vector<array<int,3>> dp(n+1);
    dp[1][0] = m * (m - 1 + mod) % mod;
    dp[1][1] = m * 3 % mod * (m - 1 + mod) % mod * (m - 2 + mod) % mod;
    dp[1][2] = m * (m - 1 + mod) % mod * (m - 2 + mod) % mod * (m - 3 + mod) % mod;
    for(int i = 2; i <= n; i++){
        dp[i][0] = ((dp[i-1][0] * (m - 1 + mod) % mod + 
                    dp[i-1][1] * (m - 2 + mod) % mod) % mod + 
                    dp[i-1][2] * (m - 3 + mod) % mod) % mod;
        dp[i][1] = ((dp[i-1][0] * 3 % mod * (m - 2 + mod) % mod * (m - 1 + mod) % mod + 
                     dp[i-1][1] * ((m - 2 + mod) * (m - 3 + mod) % mod * 2 % mod + (m - 2 + mod) * (m - 2 + mod) % mod) % mod) % mod + 
                     dp[i-1][2] * 3 % mod * (m - 3 + mod) % mod * (m - 3 + mod) % mod) % mod;
        dp[i][2] = ((dp[i-1][0] * (m - 1 + mod) % mod * (m - 2 + mod) % mod * (m - 3 + mod) % mod + 
                     dp[i-1][1] * (m - 2 + mod) % mod * (m - 3 + mod) % mod * (m - 3 + mod) % mod) % mod + 
                     dp[i-1][2] * (((m - 2 + mod) * (m - 2 + mod) % mod * (m - 2 + mod) % mod -  (m - 3 + mod) % mod * (3 * m % mod - 8 + mod) % mod) % mod + mod) % mod) % mod;
    }
    int ans = ((dp[n][0] * (m - 1 + mod) % mod + dp[n][1] * (m - 2 + mod) % mod) % mod + dp[n][2] * (m - 3 + mod) % mod) % mod;
    cout << ans << endl;
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


// n 高达 1e18时可以这样优化



// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// const int mod = 998244353;

// // 1. 定义 3x3 的矩阵结构体
// struct Matrix {
//     int mat[3][3];
//     // 构造函数：默认初始化为全 0 矩阵
//     Matrix() {
//         memset(mat, 0, sizeof(mat));
//     }
//     // 重载乘法运算符，实现矩阵乘法 (带取模)
//     Matrix operator*(const Matrix& other) const {
//         Matrix res;
//         for (int i = 0; i < 3; i++) {
//             for (int k = 0; k < 3; k++) {
//                 int r = mat[i][k];
//                 if (r == 0) continue; // 小优化：0 乘任何数都是 0
//                 for (int j = 0; j < 3; j++) {
//                     res.mat[i][j] = (res.mat[i][j] + r * other.mat[k][j]) % mod;
//                 }
//             }
//         }
//         return res;
//     }
// };

// // 2. 矩阵快速幂函数：求 base 的 p 次方
// Matrix qpow(Matrix base, int p) {
//     Matrix res;
//     // 初始化为单位矩阵 (对角线为1，相当于普通数字里的 1)
//     res.mat[0][0] = res.mat[1][1] = res.mat[2][2] = 1; 
    
//     while (p > 0) {
//         if (p & 1) res = res * base;
//         base = base * base;
//         p >>= 1;
//     }
//     return res;
// }

// void solve() {
//     int n, m; cin >> n >> m;
//     if (m == 1) {
//         cout << 0 << '\n';
//         return;
//     }

//     // 基础系数
//     int c0 = (m - 1 + mod) % mod;
//     int c1 = (m - 2 + mod) % mod;
//     int c2 = (m - 3 + mod) % mod;

//     // 3. 构建转移矩阵 M
//     Matrix M;
//     M.mat[0][0] = c0;
//     M.mat[0][1] = 3 * c0 % mod * c1 % mod;
//     M.mat[0][2] = c0 * c1 % mod * c2 % mod;

//     M.mat[1][0] = c1;
//     M.mat[1][1] = c1 * (3 * m % mod - 8 + mod) % mod;
//     M.mat[1][2] = c1 * c2 % mod * c2 % mod;

//     M.mat[2][0] = c2;
//     M.mat[2][1] = 3 * c2 % mod * c2 % mod;
//     M.mat[2][2] = (c1 * c1 % mod * c1 % mod - c2 * (3 * m % mod - 8 + mod) % mod + mod) % mod;

//     // 4. 构建初始状态行向量 F1 (把它存为一个 1x3 的矩阵，我们放在 3x3 矩阵的第一行)
//     Matrix F1;
//     F1.mat[0][0] = m * c0 % mod;
//     F1.mat[0][1] = m * 3 % mod * c0 % mod * c1 % mod;
//     F1.mat[0][2] = m * c0 % mod * c1 % mod * c2 % mod;

//     // 5. 核心：矩阵快速幂计算 M^(n-1)
//     Matrix M_n_minus_1 = qpow(M, n - 1);

//     // 计算 Fn = F1 * M^(n-1)
//     Matrix Fn = F1 * M_n_minus_1;

//     // 此时 Fn 的第一行就存放着 dp[n][0], dp[n][1], dp[n][2]
//     int dp_n_0 = Fn.mat[0][0];
//     int dp_n_1 = Fn.mat[0][1];
//     int dp_n_2 = Fn.mat[0][2];

//     // 6. 统计最终答案 (连接输出层)
//     int ans = (dp_n_0 * c0 % mod + dp_n_1 * c1 % mod + dp_n_2 * c2 % mod) % mod;
    
//     cout << ans << '\n';
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int T = 1;
//     // cin >> T;
//     while(T--) solve();
//     return 0;
// }