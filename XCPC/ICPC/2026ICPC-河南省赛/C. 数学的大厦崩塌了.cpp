#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'

// 给 0-9 映射唯一的质数，用于计算被删减数字的哈希值
const int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void solve() {
    int n;
    if (!(cin >> n)) return;

    // 分组 Map:
    // Key: [被删数字的质数哈希积, 最简比例分子, 最简比例分母]
    // Value: vector 存储满足该特征的对 {原始数值A, 删减后的数值a}
    map<array<int, 3>, vector<pair<int, int>>> groups;

    for (int A = 1; A <= n; ++A) {
        string S = to_string(A);
        int len = S.length();
        
        // 记录对于当前的 A，产生过哪些合法的 {a, hash}，避免同一种删法被重复计算
        set<pair<int, int>> unique_ah;

        // 二进制枚举子序列 (排除全选和全不选，即 mask 不能是 0 也不能是 1<<len - 1)
        for (int mask = 1; mask < (1 << len) - 1; ++mask) {
            string s_keep = "", s_drop = "";
            for (int i = 0; i < len; ++i) {
                if ((mask >> i) & 1) s_drop += S[i]; // 1 表示删掉
                else s_keep += S[i];                 // 0 表示保留
            }

            // 规则：删减后不能有前导零，且 a 至少为 1 (s_keep 不可能为空)
            if (s_keep[0] == '0') continue;
            
            int a = stoi(s_keep);
            if (a == 0) continue; // 规避 a=0 的情况
            
            // 计算被删减字符的哈希积
            int h = 1;
            for (char c : s_drop) {
                h *= primes[c - '0'];
            }
            
            unique_ah.insert({a, h});
        }

        // 把当前 A 产生的所有合法状态，化简后挂载到全局分组中
        for (auto p : unique_ah) {
            int a = p.first;
            int h = p.second;
            int g = std::gcd(a, A); // 计算最大公约数以化简比例
            
            groups[{h, a / g, A / g}].push_back({A, a});
        }
    }

    int ans = 0;

    // 遍历所有的特征组
    for (auto& [key, vec] : groups) {
        int sz = vec.size();
        if (sz < 2) continue; // 不足两个无法配对

        // 组内两两配对
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int A = vec[i].first, a = vec[i].second;
                int B = vec[j].first, b = vec[j].second;

                // 确保 A < B (因为我们是从 1 到 n 顺序插入的，自然满足 A <= B，遇到相等跳过即可)
                if (A >= B) continue;

                // 规则：a 和 b 不能有公共数字
                // 使用二进制 bitmask 快速求两个数字含有的字符交集
                int mask_a = 0, mask_b = 0;
                int temp_a = a;
                while (temp_a > 0) {
                    mask_a |= (1 << (temp_a % 10));
                    temp_a /= 10;
                }
                int temp_b = b;
                while (temp_b > 0) {
                    mask_b |= (1 << (temp_b % 10));
                    temp_b /= 10;
                }

                // 如果按位与结果为 0，说明没有任何重复数字，条件全部满足！
                if ((mask_a & mask_b) == 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}