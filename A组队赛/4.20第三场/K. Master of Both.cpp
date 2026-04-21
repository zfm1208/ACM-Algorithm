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
    * 题目背景：给定 n 个仅由小写字母组成的字符串组成的序列，总长度不超过 1e6。
    询问：有 q 次独立询问。
    每次询问会给定一个新的长度为 26 的字符串，代表一个全新的小写字母字典序排列

    目标：对于每一次询问，求出在这个全新的字母表字典序下，原字符串序列中有多少个逆序对。
    逆序对定义：满足 1 <= i < j <= n 且（在当前字母表规则下）s[j] < s[i] 的数对 (i, j)

    *字符串大小比较规则：
    <1>: 如果 a 是 b 的前缀且 a != b，则 a < b
    <2>: 如果两者在某一位开始不同，则这一位上在当前字母表中靠前的那个字符所属的字符串更小。

    * 分析
    这道题的核心痛点在于：如果每次询问都去两两比较所有字符串，时间复杂度会爆炸。
    我们需要做到查询复杂度与 n 无关。

    通过分析字符串的比较规则，我们可以将两个字符串(A,B) 产生逆序对的情况分为两类(假设A出现在B之前, 即i < j)
    <1> : 前缀关系(不受字母表顺序影响)
        如果 A 是 B 的前缀, 无论字母表怎么变, 都有 A < B，构不成逆序对
        如果 B 是 A 的前缀, 无论字母表怎么变, 都有 B < A, 永远构成逆序对, res++;
    <2> : 分叉关系(受字母表顺序影响)
    如果A 和 B 不是包含关系, 他们必然在某一位发生分叉(有一个最长的公共前缀),
    假设分叉的这一位 A 的字符是 y, B 的字符是 x
    因为 A 在 B之前, 只有当 x 的优先级 高于 y 时,才有 B < A, 构成逆序对
    因此我们可以定义一个二维数组a[x][y], 表示前面的字符串在分叉字符为y, 当前字符串在分叉字符为 x 的总配对数

    * 算法流程
    1. 我们可以建立一个字典树 (Tire)
    2. 按顺序把n个字符串插入 Tire
    3. 每次走到某个节点分叉时, 统计之前插入的字符串中走向其他分支y 的数量，累加到a[x][y]
    4. 字符串插入完毕之后, 统计当前节点之下还有多少个之前的字符串结束在此,(说明当前字符串是它们的前缀)，累加到常数逆序对res中
    5. 询问时, 双重循环遍历字母表, 对任意优先级别更高的字符x 和优先级更低的y 累加 a[x][y]
    6. 最后答案加上res即为答案
*/

int nxt[N][26]; // Trie树子节点
int cnt[N];     // 节点的字符串数量
int a[26][26];  // a[x][y]：首不同位 x vs y 的串对数量
int res = 0;      // 前缀型逆序对总数
int id = 0;       
void insert(const string& s) {
	int p = 0; 
	for(int i = 0; i < (int)s.size(); i++){
        int x = s[i] - 'a';
		// 统计在这个节点发生分叉的情况
		for(int j = 0; j < 26; j++) {
			if(j != x && nxt[p][j] != 0) { 
                
                //*  当前字符是 x，之前插入的字符是 j
                /*
                    当前我们正在插入的字符串的某个字符 X, 走在字典树节点 p 上
                    nxt[p][j] 代表从节点p沿着j走下去的路径
                    因为我们是"按顺序" 插入的这n个字符串, 所以此时Tire树里存在的节点，全部都来自之前的字符串
                    cnt[nxt[p][j]] 就是 "排在当前字符串前面, 并且在这里分叉j字符" 的字符串个数
                    将它累加a[x][j]中, 就是 后面字符串在这个位置是x,前面字符串在这个位置是j 的总次数
                */
				a[x][j] += cnt[nxt[p][j]]; 
			}
		}

		if (!nxt[p][x]) nxt[p][x] = ++id;
		p = nxt[p][x];
		cnt[p]++; // 记录经过这个节点的字符串数量
	}
	// 统计 前缀型 逆序对 res
	for(int i = 0; i < 26; i++) {
		if(nxt[p][i] != 0) res += cnt[nxt[p][i]]; 
	}
}
void solve() {
	int n,q; cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s; cin >> s; 
        insert(s);
	}
	while(q--) {
		string s; cin>>s;
		int ans = 0;
		// 遍历新的字母表，s[0] 是最小的字母，s[25] 是最大的字母
		for(int i = 0; i < 26; i++) {
			int x = s[i] - 'a';
			for(int j = i + 1; j < 26; j++) {
				int y = s[j] - 'a';
                // 在新字母表中 x < y，所以我们要把 "当前是 x, 之前是 y" 的分叉数量加入逆序对
				ans += a[x][y];
			}
		}
		cout << ans + res << '\n';
	}
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