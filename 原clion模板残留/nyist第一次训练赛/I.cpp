#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
vector<int> p(N);
bool check(int i){
    if(p[i] > p[i + 1] && p[i] > p[i - 1])return true;
    if(p[i] < p[i - 1] && p[i] < p[i + 1]) return true;
    return false;
}
void solve() {
    int n;cin >> n;
    for(int i = 1; i <= n; i++)cin >> p[i];
    vector<int> a;
    a.push_back(p[1]);
    for(int i = 2; i < n; i++){
        if(check(i)) a.push_back(p[i]);
    }
    a.push_back(p[n]);
    cout << a.size() << endl;
    for(auto i: a){
        cout << i << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
// 4
// 1 3 4 2
//
// 1 4 2