#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 20 * MAXN; // 根据n的总和调整大小

struct Node {
    int l, r, sum;
} nd[MAXM];
int root[MAXN], tot;

void update(int &now, int pre, int l, int r, int pos) {
    now = ++tot;
    nd[now] = nd[pre];
    nd[now].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(nd[now].l, nd[pre].l, l, mid, pos);
    else update(nd[now].r, nd[pre].r, mid+1, r, pos);
}

int query(int now, int l, int r, int x) {
    if (!now) return 0;
    if (x > r) return nd[now].sum;
    if (x <= l) return 0;
    int mid = (l + r) >> 1;
    int res = query(nd[now].l, l, mid, x);
    if (x > mid) res += query(nd[now].r, mid+1, r, x);
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];
    tot = 0;
    for (int i=1; i<=n; ++i) {
        update(root[i], root[i-1], 1, n, a[i]);
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        int x = a[c];
        int k = query(root[r], 1, n, x) - query(root[l-1], 1, n, x);
        cout << l + k << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}