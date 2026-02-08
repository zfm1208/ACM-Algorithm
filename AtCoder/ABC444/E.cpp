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
    题目让求pair [l,r] 个数
    满足区间 a[l] ... a[r] 任意两个数的差值 >= d
    也就是不存在两个数 的差值 < d
    双指针维护即可
    用multiset存区间里面的数, 看看是否里面是否有元素与 a[r] 不合法
    |a[r] - x| < d   ==>  a[r] - d < x < a[r] + d 
    如果有，那就左指针++
    每次ans += r - l + 1;
*/
void solve(){
    int n,d; cin >> n >> d;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    multiset<int> st;
    int l = 1,r = 1;
    for(; r <= n; r++){
        while(1){
            auto it = st.upper_bound(a[r] - d);
            if(it != st.end() && *it < a[r] + d){
                st.erase(a[l]);
                l++;
            }else{
                break;
            }
        }
        st.insert(a[r]);
        ans += (r - l + 1);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}