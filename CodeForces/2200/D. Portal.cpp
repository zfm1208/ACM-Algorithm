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
    讲数组分成3部分，找到中间部分的最短序列，然后遍历前后部分，看看什么时候插入中间部分就可
    迭代器范围是左闭右开
*/
void solve(){
    int n, x, y; 
    cin >> n >> x >> y;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    vector<int> b(p.begin() + x, p.begin() + y);
    vector<int> s;
    for(int i = 0; i < x; i++) s.pb(p[i]);
    for(int i = y; i < n; i++) s.pb(p[i]);
    auto it = min_element(b.begin(), b.end());
    vector<int> c;
    c.insert(c.end(), it, b.end()); 
    c.insert(c.end(), b.begin(), it); 
    bool ok = false; 
    for(int i = 0; i < s.size(); i++){
        if(!ok && s[i] > c[0]){
            for(int b : c) cout << b << " ";
            ok = true;
        }
        cout << s[i] << " ";
    }
    if(!ok){
        for(int x : c) cout << x << " ";
    }
    cout << endl;
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