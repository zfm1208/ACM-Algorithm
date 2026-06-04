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
const int N = 17600, mod = 1e9 + 7;

/*
题目要求：
从 1 到 17600 中选出 2025 个数，要求任意两个数互质。
问有多少种不同选法，答案对 1e9 + 7 取模。
本题是结果填空题，没有输入，只需要输出最后的整数答案。

中文思路：
1. 先数一下 1 到 17600 中有多少个质数，结果正好是 2024 个。
2. 要选 2025 个数，并且两两互质。
3. 除了数字 1 以外，每个大于 1 的数都至少会占用一个质因子。
4. 两两互质意味着不同数字不能共用质因子。
5. 现在质数总共只有 2024 个，却要选 2025 个数，所以数字 1 必须被选中。
6. 剩下 2024 个大于 1 的数，刚好对应 2024 个质数。
7. 因此每个被选中的大于 1 的数只能含有一个质因子，也就是只能是质数幂：p, p^2, p^3, ...
8. 对每个质数 p，都必须从所有不超过 17600 的 p 的幂中选一个。
9. 所以答案就是所有质数 p 的可选幂次数量的乘积。
*/
void solve(){
    vector<int> isPrime(N + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    // 埃氏筛，找出 1 到 17600 中的所有质数。
    for(int i = 2; i * i <= N; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= N; j += i){
                isPrime[j] = 0;
            }
        }
    }

    int ans = 1;
    int primeCnt = 0;

    for(int p = 2; p <= N; p++){
        if(!isPrime[p]) continue;
        primeCnt++;

        // cnt 表示 p, p^2, p^3, ... 中有多少个不超过 17600。
        int cnt = 0;
        int x = p;
        while(x <= N){
            cnt++;
            x *= p;
        }

        ans = ans * cnt % mod;
    }

    // primeCnt 会等于 2024，说明 1 必选，其余每个质数各选一个质数幂。
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // 本题无输入，T 不需要读取。
    while(T--)
        solve();
    return 0;
}
