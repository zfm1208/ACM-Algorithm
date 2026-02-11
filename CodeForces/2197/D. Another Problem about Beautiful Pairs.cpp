#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; i++)
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
    ai >= 1
    a[i] * a[j] = j - i > 1
    两层循环枚举x,y(对应a[i],a[j])
   (1 <= x,y < n && x*y < n)
    时间复杂度n/1 + n/2 + n/3 + ... n/ i + .. n/ n
    近乎于NlogN
    枚举x,y说明右式j-i，也就是x和y的下标距离已经确定了
    那么只要找是否有合法的x，即可

    由于我们是枚举数值，那我们可以用map套vector来存储每个值x对应的下标
    然后后续检查x,y是否合法时，可以适当减枝
    因为从x中找y和从y中找x是一样的，只是枚举的数量可能不同罢了(目的减枝)
*/

/*
    
    tar: 找满足 a[i] * a[j] = j - i 的数对(i,j)数量
    
    1. 性质：
       由于 j - i 的最大值为 n-1，故必须满足 a[i] * a[j] < n
       只记录 < n 的数值及其下标位置即可

    2. 实现(枚举数值而非下标)：
        使用map<int,vector<int>> mp 记录每个数值 x 出现的所有下标
        外层循环：枚举数值 x [1 ~ n)
        内层循环：枚举数值 y，满足 x * y < n
        (调和级数复杂度，约 O(N log N))
    3. 减枝：
        对于确定的一对数值(x, y)，目标下标距离为 d = x * y
        为了验证是否存在这样的(i, j)，我们需要遍历下标列表
        策略：始终遍历 size 较小的那个键值(mp[x] 或 mp[y])
        若遍历 mp[x](下标 i)：检查位置 i + d 处的值是否为 y
        若遍历 mp[y](下标 j)：检查位置 j - d 处的值是否为 x
         
    4. 复杂度分析：
        时间复杂度：O(N * sqrt(N)) ~ O(N log N)
        2e5 * 1e3 ~= 2e8 
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < n) mp[a[i]].pb(i);
    }
    int ans = 0;
    for(int x = 1; x < n; x++)
    {
        if(mp[x].size())
        {
            for(int y = 1; x * y < n; y++)
            {
                if(mp[y].size())
                {
                    int d = x * y;
                    if(mp[x].size() <= mp[y].size()){
                        for(auto i : mp[x]){
                            if(i+d <= n && a[i+d] == y){
                                ans++;
                            }
                        }
                    }else{
                        for(auto j : mp[y]){
                            if(j-d >= 1 && a[j-d] == x){
                                ans++;
                            }
                        }
                    }
                }
            }            
        }
    }
    cout << ans << endl;
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