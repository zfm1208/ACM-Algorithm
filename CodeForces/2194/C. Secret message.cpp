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
void solve1(){
    int n,k; cin >> n >> k;
    vector<int> col(n);
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            col[j] |= (1 << (s[j] - 'a'));
        }
    }
    for(int d = 1; d <= n; d++){
        if(n % d != 0) continue;
        string ans;
        bool ok = 1;
        for(int i = 0; i < d; i++)
        {
            int sum = (1 << 26) - 1;
            for(int j = i; j < n; j += d)
            {
                sum &= col[j];
            }
            if(sum == 0){
                ok = 0;
                break;
            }
            ans += (char)('a' + __builtin_ctz(sum));
        }
        if(ok){
            rep(i,1,n/d) cout << ans;
            cout << endl; return;
        }
    }
}
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> b(n+1,vector<int>(30));
    for(int i = 1; i <= m; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            b[j][s[j] - 'a']++;
        }
    }
    vector<int> yz;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            yz.pb(i);
            if(i * i != n){
                yz.pb(n/i);
            }
        }
    }
    sort(yz.begin(), yz.end());
    for(auto d: yz){
        bool ok = 0;
        string ans; // 最小的单位串
        for(int i = 0; i < d; i++) // 以i为起点
        {
            int ok1 = 0;
            for(int j = 0; j < 26; j++) // 看看哪个颜色都存在
            {
                int cnt = 0;
                for(int q = 0; q < n/d; q++) //共 n/q 份
                { 
                    // a[i+0*d] a[i+1*d] a[i+2*d] a[i+3*d]
                    if(b[i+q*d][j] > 0)
                    {
                        cnt++;
                    }else{
                        break;
                    }
                }
                if(cnt == n/d)
                {
                    ok1 = 1;
                    ans += char(j + 'a');
                    break;
                }
            }
            if(ok1 == 0){
                ok = 1;
                break;
            }
        }

        if(ok == 0){
            rep(i,1,n/d) cout << ans;
            cout << endl;
            return;
        }
    }
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