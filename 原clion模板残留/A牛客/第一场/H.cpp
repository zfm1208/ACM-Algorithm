#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
struct Node {
    int a = 0;
    int b = 0;
    int bumber = 0;
};
bool cmp(Node d1, Node d2) {
    return d1.a < d2.a;
}
bool operator <(Node d1, Node d2) {
    return d1.b > d2.b;
}
vector<int> ans(N);
deque<Node> node;
void solve() {
    int n;cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        Node temp;
        temp.a = a;
        temp.b = b;
        temp.bumber = i;
        node.push_back(temp);
    }
    sort(node.begin(), node.end(), cmp);
    priority_queue<Node> st;
    for (int i = 1; i <= n; i++)
    {
        while (node.size() && node.front().a <= i) {
            st.push(node.front());
            node.pop_front();
        }
        if (!st.size()) {
            cout << -1 << endl;
            return;
        }
        Node pos = st.top();
        st.pop();
        if (pos.b < i) {
            cout << -1 << endl;
            return;
        }
        ans[pos.bumber] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}
