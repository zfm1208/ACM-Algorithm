// O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
// O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define se second
#define fi first
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int, int>
const int N = 5e6 + 10;
int op = 0;
void solve()
{
    cout << "Case #" << ++op << ":" << endl;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)cin >> a[i];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = v.size() + 1;
        int pos = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            // 在v[]找找大于a[i]的最小值的下标
            if(v[mid] >= a[i]){
                pos = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(pos == v.size()){
            v.push_back(a[i]);
        }else{
            v[pos] = a[i];
        }
    }
    cout << n - v.size() << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    //    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
// 10, 9, 2, 5, 3, 7, 101, 18