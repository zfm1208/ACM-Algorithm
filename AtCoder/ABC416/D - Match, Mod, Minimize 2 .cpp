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
    int n,m; cin >> n >> m;
    vector<int> a(n+1),b(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        sum += b[i];
    }
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());
    int cnt = 0;
    int i = 1, j = n;
    while(i <= n && j >= 1){
        if(a[i] + b[j] >= m){
            cnt++;
            i++;
            j--;
        }else{
            i++;
        }
    }
    cout << sum - cnt * m << endl;
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