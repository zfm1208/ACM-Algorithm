#include <bits/stdc++.h>
using namespace std;

#define int long long

// ==========================================
// 字符串哈希 (String Hash) 模板
// ==========================================
const int N = 1000005;    
const int mod = 998244353; // 大质数模数 (防 Hack 可换 1e9+9, 1e9+7)
const int base = 131;      // 底数 (通常选 131, 233, 13331 等大于字符集的质数)

int p[N];       // 存储 BASE 的幂次
int h[N];       // 存储主串的前缀哈希
// int h2[N];   // 如果有多个字符串，可以多开几个哈希数组

void init() {
    p[0] = 1;
    for(int i = 1; i < N; i++){
        p[i] = p[i - 1] * base % mod;
    }
}

// 2. 构建字符串的前缀哈希数组
// 传入原生的 0-based 字符串，自动按 1-based 构建哈希
void build_hash(const string& s, int hs[]) {
    int n = s.length();
    hs[0] = 0;
    for (int i = 1; i <= n; i++) {
        hs[i] = (hs[i - 1] * base % mod + s[i - 1]) % mod;
    }
}

// 3. 获取字符串中 1-based 闭区间 [l, r] 的哈希值 (O(1) 时间)
// 要求：1 <= l <= r <= n
int get_hash(int hs[], int l, int r) {
    int res = (hs[r] - hs[l - 1] * p[r - l + 1] % mod) % mod;
    return (res + mod) % mod; 
}

// 演示如何使用：
void solve() {
    string s = "abacaba";
    build_hash(s, h); // 构建哈希

    // 查询 "aba" (第 1 到 3 个字符)
    int hash1 = get_hash(h, 1, 3);
    
    // 查询 "aba" (第 5 到 7 个字符)
    int hash2 = get_hash(h, 5, 7);

    if (hash1 == hash2) {
        cout << "Match!" << "\n";
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    // cin >> T;
    while(T--)
        solve();
    return 0;
}