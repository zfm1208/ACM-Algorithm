#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;
double dis(pii a, pii b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
bool cmp(pii a, pii b){
    return abs(a.first) < abs(b.first);
}
bool cpm(pii a, pii b){
    return abs(a.second) < abs(b.second);
}
void solve() {
    int n;cin >> n;
    vector<pii> b, c;
    pii a;
    for(int i = 1; i <= 2 * n; i++){
        cin >> a.first >> a.second;
        if (a.first == 0) {
            b.push_back(a);
        } else {
            c.push_back(a);
        }
    }
    sort(b.begin(), b.end(),cpm);
    sort(c.begin(), c.end(),cmp);
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += dis(b[i], c[i]);
    }
    printf("%.15lf\n", sum);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}