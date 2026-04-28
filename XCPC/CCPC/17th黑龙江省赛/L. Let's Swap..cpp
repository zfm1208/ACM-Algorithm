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
const int N = 1e6+5, inf = 1e18 + 5;
/*
    123456 l = 2
    216543 : 654321 -> 216543
    对长度为 l 的前缀执行题目的操作
    == 先翻转 在右移l长度

    题目允许我们使用的长度只有 l1 l2
    由于对一个字符串“向右移位再反转”等同于“反转再向左移位”
    所以一组操作(2次)(l1,l2) 之后相当于纯粹的向右循环移动 l2-l1 位

    <1> : 执行偶数次操作,相当于移动|l2 - l1|, 对于长度为n的环，
    根据 裴蜀定理 ，可以产生所有gcd(|l2-l1|, n) 倍数的位移

    <2> : 执行奇数次操作，等价于先操作偶数次再执行一次l1 / l2
    等价于 先翻转字符串，在右移(l1 / l2) ， 在加上任意次gcd(|l2-l1|, n) 倍数的位移


    令g = gcd(|l1-l2|, n)
    <1>: T 由 S 右移 x 位 (x % g = 0)
    <2>: T 由 S`右移 x 位 (x % g = l1 / l2) (S` 是 S 翻转 )
    (l1 % g == l2)

    判断2个字符串是否相等, 字符串hash
*/
typedef unsigned long long ull;
const int mod = 998244353;
int base = 1145141;
int p[N];
int hs[N];
int rhs[N];
void init(){
    p[0] = 1;
    for(int i = 1; i < N; i++){
        p[i] = p[i - 1] * base % mod;
    }
}
int get_hash(int h[], int l, int r){
    return (h[r] - h[l-1] * p[r - l + 1] % mod + mod) % mod;
}

void solve(){
    string s, t;
    cin >> s >> t;
    int l1, l2;
    cin >> l1 >> l2;

    int n = s.length();
    int g = gcd(abs(l1 - l2), n);
    string tt = " " + t;
    int tar_hs = 0;
    for(int i = 1; i <= n; i++){
        tar_hs = (tar_hs * base % mod + tt[i]) % mod;
    }

    string ss = " " + s + s;
    hs[0] = 0;
    for(int i = 1; i <= 2 * n; i++){
        hs[i] = (hs[i-1] * base % mod + ss[i]) % mod;
    }
    for(int i = 1; i <= n; i++){
        if(get_hash(hs, i, i + n - 1) == tar_hs) {
            if(((n - (i-1)) % n) % g == 0){
                cout << "yes\n";
                return;
            }
        }
    }

    string rs = s;
    reverse(rs.begin(), rs.end());
    string rss = " " + rs + rs;

    rhs[0] = 0;
    for(int i = 1; i <= 2 * n; i++){
        rhs[i] = (rhs[i-1] * base % mod + rss[i]) % mod;
    }    
    for(int i = 1; i <= n; i++){
        if(get_hash(rhs, i, i + n - 1) == tar_hs) {
            if(((n - (i - 1)) % n) % g == (l1 % g + g) % g){
                cout << "yes\n";
                return;
            }
        }
    }
    cout << "no\n";
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