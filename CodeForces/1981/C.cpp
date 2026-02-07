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
    <1>: a[i] = a[i+1]/2
    <2>: a[i+1] = a[i]/2
    => 数组中相邻的两个格子，在二叉树中必须有一条边相连(父子关系)
    1.  x -> x/2
    2.  x/2 -> x

    solution:
    对于整个数组的前缀-1，和后缀-1，单独讨论即可
    对于中间的一段-1，我们记为[L,-1,-1,...,-1,R]
    L,R看看谁大，双指针填坑：谁大谁就往中间缩，最后检查下合不合法即可
           L              R
          lst             i
    ... 1, 2, -1, -1,..., 3, 6, ...
*/

/*
    <1>: 数字变化规则对应什么图/树结构
    <2>: 以已知数为界，切断，只看两个桩子中间怎么填
    <3>: 数值大的往数值小的方向靠拢（降维）/ 或者两头往中间凑
    <4>: 凑到一起后，检查接口能不能对上（是否合法）
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+2);
    rep(i,1,n) cin >> a[i];
    if(count(a.begin()+1,a.end(),-1) == n){
        rep(i,1,n) cout << ((i&1) ? 1 : 2) << " \n"[i==n];
        return;
    }
    auto get = [&] (int x) -> int {
        if(x == 1) return 2;
        return x / 2;
    };
    int lst = 0; // 上一个不为 -1 的位置
    for(int i = 1; i <= n; i++){
        if(a[i] != -1)
        {
            if(lst == 0) // 前缀-1
            { 
                for(int k = i-1; k >= 1; k--){
                    a[k] = get(a[k+1]);
                }
                lst = i;
            }else{ // 中间 -1
                int l = lst;
                int r = i;
                while(l + 1 < r){
                    if(a[l] > a[r]){
                        a[l+1] = get(a[l]);
                        l++;
                    }else{
                        a[r-1] = get(a[r]);
                        r--;
                    }
                }
                if((a[l] != a[r] / 2) && (a[l] / 2 != a[r])){
                    cout << -1 << endl;
                    return;
                }
                lst = i;
            }
        }
    }
    for(int i = lst + 1; i <= n; i++){ // 后缀-1
        a[i] = get(a[i-1]);
    }
    rep(i,1,n) cout << a[i] << " \n"[i==n];

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