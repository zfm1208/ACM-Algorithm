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
/*
    很好的贪心题目
    m项技能，每个技能都有ki个认会，那么所有人掌握的总技能点数是 sum
    压低“全能”人数的贪心策略：
    题目要求至少有多少人m项都会(把“全能”的人数降到最低)
    为了让尽量少的人拿满m个技能点，我们应该把你能点分给其他人，
    让尽可能多的人只拿m-1个技能点

    一共n人，每个人都恰好只能m-1个技能点，总共n*(m-1)
    那么剩下的技能点就只能会让全能的人拿
    ans = max(0LL, sum - n * (m-1))
*/

/*
    另一种思路(逆向思维):
    与其去算“谁会这项技能”，不如去算“谁不会这项技能”。
    一个人只要不会其中任意 1 项，他就不是全能。
    我们要让全能的人尽量少，就是要让“不全能”的人尽量多。

     第 i 项技能有 k_i 个人会，就有 n - k_i 个人不会。
     把所有技能“不会”的人数加起来 
     记为tot = ran(i,1,m) n - k_i = m*n - sum
    
     贪心分散漏洞： 为了让尽可能多的人“不全能”（即至少拥有 1 个漏洞），
     我们应该把这 m * n - sum 个漏洞，
     尽量每人只分 1 个，分给不同的人

     tot >= n  ans -> 0
     tot < n   ans -> max(0LL, n - (m*n-sum))
*/
void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    int sum = 0;
    rep(i, 1, m){
        cin >> a[i];
        sum += a[i];
    }
    cout << max(0ll, sum - n * (m - 1));
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