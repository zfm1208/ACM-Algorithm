//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n,d; cin >> n >> d;
    // 求一个数数位个数
    int len = to_string(n).size();
    // 将一个数a构造成一个可以被n整除的数b  要求构造的数b中保留完整的a
    // 如a==1234567898   b==1234567898005  就是合法的
    int num = (1234567890+d)*pow(10,len);
    //例如 7778 构造成x  (x%n==0)
    // 若n==374
    // 7778 -> 7778000 -> 7778374
    // 7778374 % 374==296
    // 7778374 - 296 = 7778078
    // 7778078 % 374 = 0
    // 合法
    num += n;
    num -= num%n;
    cout << num/n << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
