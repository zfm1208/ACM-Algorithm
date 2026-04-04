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
// https://acm.hdu.edu.cn/contest/problem?cid=1199&pid=1004

/*
    这一题如果我们直接for 枚举每一位，然后再统计该位因子，会超时n*sqrt(n)
    我们肯定要通过预处理来缩减时间复杂度

    对于一个编号 i ,
    它的 真因数, 编号比i小的且能被i整除的; count = i 的总因子个数 - 1(本身)

    它的 倍数, 编号[1,n]之间,且是1的倍数; count = n/i - 1(本身)

    编号为i 的人气值为 (i的总因数个数) + (n/i) - 2;

    所以我们只需要预处理出来1-N每个数的因数个数即可
*/
vector<int> yz(N+10);
void init(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            yz[j]++;
        }
    }
}
void solve(){
    int n,k; cin >> n >> k;
    vector<int> du(n+1);
    for(int i = 1; i <= n; i++){
        du[i] = (yz[i] - 1) + (n/i - 1);
    }
    sort(du.begin()+1,du.end(),greater<int>());
    cout << du[k] << endl;
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