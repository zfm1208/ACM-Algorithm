//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i].first;
    for(int i = 1; i <= n; i++)
        cin >> a[i].second;
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++)
        b[i] = a[i].second - a[i].first;
    sort(b.begin()+1, b.end());
    int cnt = 0;
    for(int i = 1,j = n; i < j;){
        if(b[i] + b[j] >= 0) {
            cnt++;
            i++;
            j--;
        }else{
            i++;
        }
    }
    cout << cnt << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
