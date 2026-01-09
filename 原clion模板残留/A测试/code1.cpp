// Enable Power Mode
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define piii pair<int, pair<int, int>>
#define pii pair<int, int>
#define int long long
#define ld long double
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
double pi = acos(-1);
const int mod = 1e9 + 7, mod1 = 998244353, inf = 1e18 + 5;
const int N = 1e5 + 5;
const int inv2 = 5e8 + 4;
using i64 = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int lst = 1, tag = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            lst++;
            while (tag) {

                while (st.count(lst)) {
                    lst++;
                }
                tag--;
                lst++;
            }
            st.insert(lst);
        } else {
            lst++;
            while (tag) {
                while (st.count(lst)) {
                    lst++;
                }
                lst++;
                tag--;
            }
            while (st.count(lst)) {
                lst++;
            }
            st.insert(lst);
            tag++;
        }
    }
    cout << st.size() << endl;
    for (auto t : st) {
        cout << t << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    //    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}