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
const int N = 1e5 + 10, mod = 1e9+7, inf = 1e18 + 5;
struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int x, int val) {
        for (; x <= n; x += x & -x) tree[x] += val;
    }
    
    int query(int x) {
        int sum = 0;
        for (; x > 0; x -= x & -x) sum += tree[x];
        return sum;
    }
    
    int query1(int x) {
        if (x >= n) return 0;
        return query(n) - query(x);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> cnt(n + 1, 0);
    vector<int> pos2(n + 1, n + 2); 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            pos2[a[i]] = i;
        }
    }
    vector<int> B(n + 1);
    int M = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > M) {
            B[i] = M; 
            M = a[i];
        } else {
            B[i] = a[i];
        }
    }

    BIT bit(n);
    vector<bool> seen(n + 1, false);
    
    int cur = 0;
    int L1 = 0;
    int prefC = 0;     

    for (int k = 1; k <= n; k++) {
        if (a[k] > cur) {
            cur = a[k];
            L1++;
        }
        if (k >= 2) {
            prefC += bit.query1(B[k]);
            if (B[k] >= 1 && !seen[B[k]]) {
                seen[B[k]] = true;
                bit.add(B[k], 1);
            }
        }
        int term1 = L1 - 1;
        int term2 = prefC;
        int p2 = pos2[cur];
        int term3 = max(0LL, min((int)k, p2 - 1) - 1);

        cout << term1 + term2 + term3 << (k == n ? "" : " ");
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}