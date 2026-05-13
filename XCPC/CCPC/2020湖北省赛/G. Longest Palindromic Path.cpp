#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

// PAM 核心数组
int ch[MAXN][26];  // 字典树转移边
int fail[MAXN];    // 失配指针（指向最长回文后缀）
int len[MAXN];     // 节点代表的回文串长度
int par[MAXN];     // 记录父节点 (也就是去掉首尾字符后的回文串)
int dp[MAXN];      // dp[i] 表示以节点 i 结尾的最长回文包含路径长度

char s[MAXN];
int sz, last;

// 初始化，多测清空
void init() {
    // 为了防止 TLE，只清空上一次用到的节点，不要全盘 memset
    for (int i = 0; i <= sz; ++i) {
        memset(ch[i], 0, sizeof(ch[i]));
        fail[i] = len[i] = par[i] = dp[i] = 0;
    }
    
    sz = 1;     // 当前节点数 (0 和 1 被初始根节点占用)
    last = 0;   // 上一个字符对应节点
    
    // 1-base 字符串的安全边界符
    s[0] = '#'; 
    
    // 节点 0：偶数长度根节点
    len[0] = 0;  
    fail[0] = 1; 
    
    // 节点 1：奇数长度根节点
    len[1] = -1; 
    fail[1] = 1; 
}

// 沿着 fail 链寻找能成功匹配前后字符的节点
int get_fail(int u, int i) {
    while (s[i - len[u] - 1] != s[i]) {
        u = fail[u];
    }
    return u;
}

void solve() {
    cin >> (s + 1); // 1-base 读入
    int n = strlen(s + 1);

    init();

    // 1-base 遍历字符串构建 PAM
    for (int i = 1; i <= n; ++i) {
        int c = s[i] - 'a';
        int u = get_fail(last, i);

        // 如果这个回文串没有出现过，新建节点
        if (!ch[u][c]) {
            int np = ++sz;
            len[np] = len[u] + 2;
            par[np] = u; // 核心逻辑：记录去掉两端字符后的"内部"回文串
            
            // fail 指针指向：父节点 fail 链对应能匹配的前后缀，加上字符 c
            fail[np] = ch[get_fail(fail[u], i)][c];
            
            ch[u][c] = np;
        }
        last = ch[u][c];
    }

    int ans = 0;
    // 节点 0 和 1 是虚根，真正的回文串节点是从 2 到 sz
    // 因为建树过程保证了父节点和 fail 节点的编号一定小于当前节点编号，天然满足拓扑序
    for (int i = 2; i <= sz; ++i) {
        // 状态转移方程：当前节点的路径长度 = 1 + max(内部回文串路径, 后缀回文串路径)
        dp[i] = 1 + max(dp[par[i]], dp[fail[i]]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

int main() {
    // 优化输入输出流速度，避免 TLE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}