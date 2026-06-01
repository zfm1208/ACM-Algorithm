#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

const int INF = 1e9 + 7;
struct Node {
    int min_val;
    int lazy;
} tree[800005];

int prefB[200005]; 

void push_up(int node) {
    tree[node].min_val = min(tree[node * 2].min_val, tree[node * 2 + 1].min_val);
}

void push_down(int node) {
    if (tree[node].lazy != 0) {
        tree[node * 2].min_val += tree[node].lazy;
        tree[node * 2].lazy += tree[node].lazy;
        tree[node * 2 + 1].min_val += tree[node].lazy;
        tree[node * 2 + 1].lazy += tree[node].lazy;
        tree[node].lazy = 0;
    }
}

void build(int node, int l, int r) {
    tree[node].lazy = 0;
    if (l == r) {
        tree[node].min_val = prefB[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    push_up(node);
}

void update(int node, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        tree[node].min_val += val;
        tree[node].lazy += val;
        return;
    }
    push_down(node);
    int mid = l + (r - l) / 2;
    if (ql <= mid) update(node * 2, l, mid, ql, qr, val);
    if (qr > mid) update(node * 2 + 1, mid + 1, r, ql, qr, val);
    push_up(node);
}

int query_min(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[node].min_val;
    push_down(node);
    int mid = l + (r - l) / 2;
    int res = INF;
    if (ql <= mid) res = min(res, query_min(node * 2, l, mid, ql, qr));
    if (qr > mid) res = min(res, query_min(node * 2 + 1, mid + 1, r, ql, qr));
    return res;
}

int find_first_zero(int node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql || tree[node].min_val > 0) return -1;
    if (l == r) return l;
    push_down(node);
    int mid = l + (r - l) / 2;
    int res = find_first_zero(node * 2, l, mid, ql, qr);
    if (res != -1) return res;
    return find_first_zero(node * 2 + 1, mid + 1, r, ql, qr);
}

struct Query {
    long long b;
    int id;
    bool operator<(const Query& other) const {
        return b > other.b; 
    }
};

struct SellPoint {
    long long v;
    int id;
    bool operator<(const SellPoint& other) const {
        return v > other.v; 
    }
};

void solve() {
    int n;
    long long a;
    cin >> n >> a;
    
    vector<long long> v(n + 1);
    long long K = 0, SumA = 0;
    
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        prefB[i] = prefB[i - 1];
        if (v[i] <= a) {
            K++;
            SumA += v[i];
            prefB[i]++;
        }
    }
    
    int m;
    cin >> m;
    vector<Query> qus(m);
    for (int i = 0; i < m; ++i) {
        cin >> qus[i].b;
        qus[i].id = i;
    }
    
    sort(qus.begin(), qus.end());
    
    vector<SellPoint> sells;
    for (int i = 1; i <= n; ++i) {
        if (v[i] > a) { 
            sells.push_back({v[i], i});
        }
    }
    sort(sells.begin(), sells.end());
    
    build(1, 1, n);
    
    vector<long long> ans(m);
    set<int> st;
    long long sum1 = 0;
    
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        long long cur1 = qus[i].b;
        
        while (cnt < sells.size() && sells[cnt].v >= cur1) {
            int x = sells[cnt].id;
            long long val_x = sells[cnt].v;
            
            int min_D = query_min(1, 1, n, x, n);
            if (min_D > 0) {
                st.insert(x);
                sum1 += val_x;
                update(1, 1, n, x, n, -1);
            } else {
                int z = find_first_zero(1, 1, n, x, n);
                if (z != -1) {
                    auto it = st.upper_bound(z);
                    if (it != st.begin()) {
                        --it;
                        int y = *it;
                        if (y > x) { 
                            sum1 -= v[y];
                            update(1, 1, n, y, n, 1);
                            st.erase(it);
                            
                            st.insert(x);
                            sum1 += val_x;
                            update(1, 1, n, x, n, -1);
                        }
                    }
                }
            }
            cnt++;
        }
        long long rem = K - st.size();
        ans[qus[i].id] = sum1 + rem * v[n] - SumA;
    }
    
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << (i == m - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}