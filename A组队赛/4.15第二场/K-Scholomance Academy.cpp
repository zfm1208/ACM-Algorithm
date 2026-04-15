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
struct node {
    char c;
    int x;
    bool operator<(const node& other) const {
        return x > other.x; 
    }
};
void solve(){
    int n; cin >> n;
    vector<node> a(n);
    int P = 0, M = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].c >> a[i].x;
        if(a[i].c == '+') P++;
        else M++;
    }
    sort(a.begin(), a.end());
    int tot = 0,sum = 0;
    for(int i = 0; i < n;){
        int cnt_P = 0,cnt_M = 0;
        int j = i;
        while(j < n && a[j].x == a[i].x){
            if (a[j].c == '+') cnt_P++;
            else cnt_M++;
            j++;
        }
        sum += cnt_M * tot;
        tot += cnt_P;
        i = j;
    }
    double ans = (double)sum / ((double)P * M);
    cout << fixed << setprecision(10) << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T; 
    while(T--)
        solve();
    return 0;
}