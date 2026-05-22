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
    a数组
    b数组是a数组的前缀和
    c数组是b数组的前缀最大值
    1 2 -1 0
    1 2 -1 0
    1 3 2 3
    1 3 3 3

    0 0 0 4 0 0 
    2 4 -3 4 -100 0
    2 6 3 7 -93 -93
    2 6 6 7 7 7

*/


/*
    c数组由b数组觉得，我们先构造b数组，b数组有了就能轻易构造a数组
    现在重点是关注b数组
    , 那么构造的b数组和c数组有什么要求没？
    <1>: b[1] = c[1]
    <2>: b[i] <= c[i]
    <3>: b[i] == c[i] (若 c[i] > c[i-1])

    b数组由a数组决定，s字符串决定了a数组，我们可以通过s字符串来构造b数组
    <1>: s[i] == 1(已知a[i]), b[i] = b[i-1] + a[i]
    <2>: s[i] == 0(未知a[i]), ?
    
    我们去构造b数组时，b数组要构造什么样子的呢？
    要尽可能往最大的去构造，因为我们发现，当c[i] > c[i-1]时
    要满足b[i] == c[i], 如果我们去顶格构造b数组，就可以尽可能去满足达到c[i]的要求
    要是连最大值都不能满足c[i], 那更小的就更不可能了，贪心填最大值就好了

    dp[i]: 在不违反后续所有规定的前提下，当前b[i]理论上能达到的最大值
    既然 s[i] == 1 会把未来的限制往回传导，我们就必须从从后往前遍历

    dp[n] = c[n]
    站在i 看 i-1
    <1>: s[i] == 1 未来的上限是 dp[i]，那 b[i-1] 最多只能是 dp[i] - a[i]
    同时也不能超过自己本该有的上限 c[i-1];  
    dp[i-1] = min(c[i-1], dp[i] - a[i])
    <2>: s[i] == 0
    不用管未来 
    dp[i-1] = c[i-1]

    现在每个位置的最大可能值 dp 都有了，我们从前往后真正地构造 b 数组：
    <1>: s[i] = 1, b[i] = b[i-1] + a[i]
    <2>: s[i] = 0, b[i] = dp[i]

    然后判断b，c数组是否合法即可，最输出a[]
*/
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int> a(n+1),c(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    if(!is_sorted(c.begin()+1, c.end())){
        cout << "No" << endl;
        return;
    }
    vector<int> dp(n+1);
    dp[n] = c[n];
    for(int i = n; i >= 2; i--){
        if(s[i] == '1'){
            dp[i-1] = min(c[i-1], dp[i] - a[i]);
        }else{
            dp[i-1] = c[i-1];
        }
    }
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++){
        if(s[i] == '1'){
            b[i] = b[i-1] + a[i];
        }else{
            b[i] = dp[i];
        }
    }
    if(b[1] != c[1]){
        cout << "No" << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(b[i] > c[i]){
            cout << "No" << endl;
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        if(c[i] > c[i-1]){
            if(b[i] != c[i]){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++){
        a[i] = b[i] - b[i-1];
        cout << a[i] << " \n"[i==n];
    }
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