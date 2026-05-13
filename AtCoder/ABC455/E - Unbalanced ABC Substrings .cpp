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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int a = 0, b = 0, c = 0;
    vector<int> ab(n + 1), bc(n + 1), ca(n + 1);
    vector<pii> abc(n + 1);
    abc[0] = {0, 0};
    
    for(int i = 1; i <= n; i++){
        if(s[i] == 'A') a++;
        else if(s[i] == 'B') b++;
        else if(s[i] == 'C') c++;
        
        ab[i] = a - b;
        bc[i] = b - c;
        ca[i] = c - a;
        abc[i] = {a - b, b - c};
    }
    
    auto get = [&](vector<int>& vec) -> int {
        sort(vec.begin(), vec.end());
        int res = 0;
        int cnt = 1;
        int nn = vec.size();
        for(int i = 1; i <= n; i++){
            if(vec[i] == vec[i-1]){
                cnt++;
            } else {
                res += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        res += cnt * (cnt - 1) / 2;
        return res;
    };

    auto get1 = [&](vector<pii>& vec) -> int {
        sort(vec.begin(), vec.end());
        int res = 0;
        int cnt = 1;
        int nn = vec.size();
        for(int i = 1; i <= n; i++){
            if(vec[i] == vec[i-1]){
                cnt++;
            } else {
                res += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        res += cnt * (cnt - 1) / 2;
        return res;
    };
    
    int tot = get(ab) + get(bc) + get(ca) - 2 * get1(abc);   
    int ans = n * (n + 1) / 2 - tot;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T; 
    while(T--)
        solve();
    return 0;
}