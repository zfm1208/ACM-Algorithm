#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve() {
    /*
        1356678
        1112456
        Yes

        1337888
        1234567
        Yes
        
        首先特判两个序列初始时就相等的情况;
        然后考虑能够进行变换的必要条件是两个序列中都要有至少一个相邻的 pair
        考虑一对相邻的 pair 可以一直移动，并将序列中其它数的值一同带着修改
        手玩一下会发现此时操作的不变量是序列中奇数的个数，根据这个来判断即可
        一对 pair 中 奇数偶数都为1，这一对pair 同增同减，奇偶个数不变
    */
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    bool ok = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]){
            ok = 1;
            break;
        }
    }
    if(!ok){
        cout << "Yes" << endl;
        return;
    }
    bool ok1 = 0, ok2 = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i+1] - 1) ok1 = 1;
        if(b[i] == b[i+1] - 1) ok2 = 1;
    }
    if(!ok1 || !ok2) {
        cout << "No" << endl;
        return;
    }
    int add1=0, add2=0;
    for(int i = 1; i <= n; i++){
        if(a[i]&1) add1++;
        if(b[i]&1) add2++;
    }
    cout << (add1 == add2 ? "Yes" : "No") << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}