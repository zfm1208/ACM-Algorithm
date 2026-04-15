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
// https://qoj.ac/problem/5420
/*
    假设在所有的决策做完之后，我们总共选择了 x 个 1 (原来的1 + 0变成的1)
    由于事件总数是 n, 那么我们选择的 -1 的数量就是n - x
    f(x) = (x + 1) / (2 * x - n + 1)
    对这个式子进行求导，发现是单调递减的

    贪心：
    既然选的 1 越少越好，那我们的策略就很清晰了
    把所有的 0 全都当成 -1 来用！ 除非不用不行了，我们才被迫把 0 变成 1
    如果在任何时候分母数量 <= 0
    如果手里有“可反悔的筹码”（之前把 0 当成了 -1），我们就反悔一次。
    把那个 -1 改成 1，这一来一回，分母的数量会 +2，并且消耗掉一个筹码，
    选 1 的总数也会 +1。
    如果连筹码都没有了，说明这关绝对过不去，直接输出 -1
*/
void solve(){
    int n; cin >> n;
    int fm = 1,fz = 1;
    int cnt = 0;// 筹码的个数
    bool ok = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(ok) continue;
        if(x == 1){
            fm++;
            fz++;
        }else if(x == -1){
            fm--;
        }else{
            fm--;
            cnt++;
        }
        if(fm <= 0){
            if(cnt) {
                cnt--;
                fm+=2;
                fz++;
            }else{
                ok = 1;
            }
        }
    }
    if(ok){
        cout << -1 << endl;
        return;
    }
    int gc = __gcd(fm,fz);
    cout << fz/gc << " " << fm/gc << endl;
}
/*
    也可以二分答案，二分前多少个0是1
    最贪新肯定是前面的0 变成 +1 ， 后面的0是-1
*/
void solve1(){
    int n; cin >> n;
    vector<int> a(n+1);
    int cnt_0 = 0, cnt_1 = 0, cnt_f1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 0) cnt_0++;
        else if (a[i] == 1) cnt_1++;
        else if (a[i] == -1) cnt_f1++;        
    }
    auto check = [&](int m) {
        int cnt = 1;
        int cn_f1 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1){
                cnt++;
            } else if (a[i] == -1) {
                cnt--;
            } else{ 
                cn_f1++;
                if(cn_f1 <= m) {
                    cnt++; 
                }else {
                    cnt--; 
                }
            }
            if (cnt <= 0) return false; 
        }
        return true;
    };
    int l = 0, r = cnt_0;
    int ans = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;   
            r = mid - 1; 
        } else {
            l = mid + 1;
        }
    }
    if(ans == -1){
        cout << -1 << "\n";
        return;
    }
    int f1 = cnt_1 + ans;
    int q = 1 + (cnt_1 + ans) - (cnt_f1 + (cnt_0 - ans));
    int p = 1 + f1;
    int g = gcd(p, q);
    cout << p / g << " " << q / g << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve1();
    return 0;
}