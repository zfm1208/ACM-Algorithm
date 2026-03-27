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
    int n,m;
    cin >> n >> m;
    if(n == 2 && m == 2){
        cout << 0 << endl;
        return;
    }
    if(n % 2 == 1 || m % 2 == 1){
        if(n % 2 == 1){
            int ans = n * (m / 2);
            if(m % 2 == 1){
                ans += (n+1) /2;
            }
            cout << ans << endl;
        }else{
            int ans = m * (n / 2);
            cout << ans << endl;
        }
    }else{
        int res = 0;
        int nn = n,mm = m;
        n -= 2;
        n/=2;
        // n * m
        
        if(n % 2 == 1){      
            /*
                8 6
                6 6
                ans = 2 * (3 ,6)
                n 3
                m 6
            */
            int ans = n * (m / 2);
            if(m % 2 == 1){
                ans += (n+1) /2;
            }
            ans *= 2; 
            res = max(res, ans);
        }else{
            /*
                6 6
                4 6
                ans = 2 * (2 ,6)
                n 2
                m 6
            */
            int ans = n*m/2;
            ans *= 2;
            res = max(res, ans);
        }

        mm -= 2;
             /*
                6 8
                6 6
                ans = 2 * (6 ,3)
                n 6
                m 3
            */
        mm /= 2;
        if(mm % 2 == 1){
            int ans = mm * (nn / 2);
            if(nn % 2 == 1){
                ans += (mm+1) /2;
            }
            ans *= 2;
            res = max(res, ans);
        }else{
            int ans = nn*mm/2;
            ans *= 2;
            res = max(res, ans);
        }
        cout << res << endl;
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