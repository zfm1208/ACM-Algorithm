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
/*
    15 10 5
    3 2 1 2
*/
void solve(){
    int n; cin >> n;
    vii a(2 * n + 2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i+n] = a[i];
    }
    int p = -1;
    for(int i = 2; i <= n + 1; i++){
        if(a[i] > a[i - 1]){
            p = i;
            break;
        }
    }
    if(p == -1){
        cout << a[1] << endl;
        return;
    }
    int sum = 0;
    for(int i = p; i < p + n; i++){
        if(i == p || a[i] > a[i - 1]){
            sum += a[i];
        }
    }
    cout << sum << endl;
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