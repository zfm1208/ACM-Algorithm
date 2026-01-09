#include <bits/stdc++.h>
#define int long long
using namespace std;
#define ull unsigned long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define endl '\n'
#define EPS 1e-8
#define fi first
#define se second
#define lowbit(x) x & (-x)
const int inf = 1e18+5;
typedef pair<int, int> pii;
static string make_name(int idx, const char *ext)
{
    stringstream ss;
    ss << "test";
    if (idx < 10)
        ss << "0";
    ss << idx << ext;
    return ss.str();
}

static int latest_existing_idx()
{
    int idx = 1;
    while (true)
    {
        ifstream f(make_name(idx, ".in"));
        if (!f.good())
            return max(1LL, (long long)idx - 1);
        idx++;
    }
}
// 代码区:  

const int mod = 1e9+7;  
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;  
        a = a * a % mod; 
        b >>= 1; 
    }
    return res % mod;
}



signed main()
{
    // 自动读取最新存在的 testXX.in，并输出到对应的 testXX.out
    int idx = latest_existing_idx();
    string inFile = make_name(idx, ".in");
    string outFile = make_name(idx, ".out");
    freopen(inFile.c_str(), "r", stdin);
    freopen(outFile.c_str(), "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i]; 
            if(a[i] == 1) cnt++;
        } 
        if(cnt){
            cout << n-cnt << '\n';
            return 0;
        }    
        int ans = inf;
        for(int i = 1; i <= n; i++){
            int temp = a[i];
            for(int j = i+1; j <= n; j++){
                temp = __gcd(temp,a[j]);
                if(temp == 1){
                    ans = min(ans,j-i);
                    break;
                }
            }
        }
        cout << ((ans == inf) ? -1 : ans + n - 1) << '\n';
    }

}