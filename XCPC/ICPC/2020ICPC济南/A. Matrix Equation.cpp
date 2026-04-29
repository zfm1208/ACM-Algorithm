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
// https://qoj.ac/contest/2181/problem/12398
int ksm(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n; cin >> n;
    vector<bitset<205>> a(n+1);
    vector<vector<int>> b(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            a[i][j] = x;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> b[i][j];
        }
    }   
    int cnt = 0; 
    for(int lie = 1; lie <= n; lie++)
    {
        vector<bitset<205>> m = a;
        // 构造矩阵 m = A ⊕ diag
        for(int i = 1; i <= n; i++){
            m[i][i] = m[i][i] ^ b[i][lie];
        }
        int rank = 1;// rank 现在代表 “将要把主元放在第 rank 行”
        for(int i = 1; i <= n; i++)
        {
            int k = rank;
            // 往下找，在第 i 列中找到第一个是 1 的行
            while(k <= n && m[k][i] == 0) k++;
            // 如果 k > n，说明这一列全是 0，没有主元
            if(k > n) continue;
            // 把 主元行 交换到第 rank 行
            swap(m[k], m[rank]);
            // 用第 rank 行，去消掉下面所有行在第 i 列的 1
            for(int j = rank + 1; j <= n; j++){
                if(m[j][i]) {
                    m[j] ^= m[rank]; // Bitset O(1) 压位消元
                }
            }
            // 成功放置了一个主元，准备放下一行的主元
            rank++;
        }
        // 循环结束后，rank 的值等于“非零行数量 + 1”
        // 所以真实的非零行数（矩阵的秩）是 rank - 1
        cnt += (n - (rank - 1));
    }
    cout << ksm(2, cnt) << endl;
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