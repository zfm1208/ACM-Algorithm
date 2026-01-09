#include<iostream>
#include<cstdio>
#include<string>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 5e4 + 5;
int n;
int a[N],b[N];
void add(int x, int k){
    while(x <= n){
        b[x] += k;
        x += x & -x;
    }
}
int query(int x){
    int ans = 0;
    while(x){
        ans += b[x];
        x -= x & -x;
    }
    return ans;
}
int cnt = 1;
void solve() {
    cout << "Case " << cnt << ":" << endl;
    cin >> n;
    for(int i = 1; i <= n; i++){ // 多组数据，不要忘记清空数组
        b[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(i,a[i]);
    }
    string s;
    while(1){
        cin >> s;
        if(s == "End"){
            break;
        }
        if(s == "Add"){
            int x,k;cin >> x >> k;
            add(x,k);
        }else if (s == "Query"){
            int l,r; cin >> l >> r;
            cout << query(r) - query(l - 1) << endl;
        }else if (s == "Sub"){
            int x,k; cin >> x >> k;
            add(x,-k);
        }
    }
    cnt++;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
