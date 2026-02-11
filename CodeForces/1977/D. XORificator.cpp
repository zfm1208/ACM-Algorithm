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
/*
    用dp实现比较困难,改变某一行的状态会使m列的状态都改变,很难定义局部最优子结构
    应该要进行哈希预处理,预处理出来n种所有特殊列的哈希值
    如果在行上做翻转操作，每次操作完重新计算所有列，时间复杂度: (n*m*操作次数) 超时
    我们不要去模拟翻转的这个过程，也不要贪心的去找哪一行该翻转，我们要投票

    不要去试着凑行的操作, 而是让每一列告诉我们它需要什么样的操作
    我们最终希望有一个操作系列X,使得有尽可能多的特殊列
    假设我们只盯着第j列看， 这一列原本是C_j
    如果这一列需要变成特殊列，且那个唯一的行出现在第r行，那我们需要的序列操作X要满足什么？
    操作后的列状态C_j'必须 是一个只在第r行为1的向量,记为E_r
     C_j   E_r
      0    0  不变
      1    0  翻转
    r 1  ->1  不变
      0    0  不变
      1    0  翻转

      X ： 01001 = C_j ^ E_r
    
    对于第j列，只有n种行操作方案
    0  x = C_j ^ E_0
    1  x = C_j ^ E_1
    2  x = C_j ^ E_2
    .. .............
    i  x = C_j ^ E_i
    .. .............
    n-1x = C_j ^ E_n-1

    我们可以遍历每一列，算出这一列最渴望的那n种x方案是什么，然后给这n种x分别投一票

    最后看看的票最多的x是什么，就是能满足最多列的'最大公约数' 的操作方案
    为了快速存储和比较x， 我们使用异或哈希

    时间复杂的(n*m*log(n*m)) 
*/

typedef unsigned long long ull;
mt19937_64 rng(time(0));
void solve(){
    int n,m; cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ull> row_hash(n);
    for(int i = 0; i < n; i++) row_hash[i] = rng();
    vector<ull> col_hashes(m);
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(a[i][j] == '1'){
                col_hashes[j] ^= row_hash[i];
            }
        }
    }
    map<ull,int> mp;
    int mx = 0;
    int col = 0, row = 0;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            ull x = col_hashes[j] ^ row_hash[i];
            mp[x]++;
            if(mp[x] > mx){
                mx = mp[x];
                col = j;
                row = i;
            }
        }
    }
    cout << mx << endl;
    string ans;
    for(int i = 0; i < n; i++){
        if(i == row){
            if(a[i][col] != '1'){
                ans += '1';
            }else{
                ans += '0';
            }
        }else{
            if(a[i][col] != '0'){
                ans += '1';
            }else{
                ans += '0';
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}