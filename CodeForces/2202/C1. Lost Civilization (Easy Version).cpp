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
    记录当前的L,r值,对于遍历到的这个数x
    如果x > l && x <= r+1 那就更新r值
    否则就更新L = r = x; cnt++

    实际+1操作当于一个树的一条枝干向下延申,遇到一个数x,
    要么在这个枝干是继续延申，要么回溯，要么开始一段新的树枝
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    int cnt = 0;
    int l = a[1], r = a[1];
    cnt++;
    for(int i = 2; i <= n; i++){
        if(a[i] <= r+1 && a[i] > l){
            r = a[i];
        }else{
            cnt++;
            l = r = a[i];
        }
    }
    cout << cnt << endl;
}
void solve1(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    vector<int> st;
    for(int i = n; i >= 1; i--){
        while(!st.empty() && st.back() == a[i] + 1){
            st.pop_back();
        }
        st.push_back(a[i]);
    }
    cout << st.size() << endl;
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