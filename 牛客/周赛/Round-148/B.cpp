#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
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
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            int r = n / i;
            int sq = sqrt(r);
            if(r ==  sq * sq && r != 1){
                bool flag = 0;
                for(int j = 2; j * j <= sq; j++){
                    if(r % j == 0){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    cout << sq << " " << i << endl;
                    return;
                }
            }
        }
    }
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