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
    22332222331144
    33343335
    343 353 313 3

    112224444

    51556666
    323
        6 : 3
    212232242
        4 : 2
    212212
        2 : 1
    212

    212212
    454

    16141
    2 (212252) 2 +  4 (434) 4

    1122
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int cnt = 0;
    int c1 = 0;
    int sum = 0;
    int pp = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1) c1++;
        else{ 
            pp++;  
            sum += a[i];
            cnt += (a[i] - 2) / 2;
        }
    }
    if(pp == 0) cout << 0 << endl;
    else{
        if(sum < 3 && n == 1){
            cout << 0 << endl;
            return;
        }
        int ans = sum + min(cnt, c1);
        if(pp == 1){
            ans = sum + min(c1, sum / 2);
            cout << ans << endl;
            return;
        }
        cout << ans << endl;        
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