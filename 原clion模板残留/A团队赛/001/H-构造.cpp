//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 1e6 + 5;
int op = 1;
void solve() {
    cout << "Case " << op++ << ": ";
    string a,b;cin >> a >> b;
    int n = (int)a.size();
    vector<int> f(n+1,0);
    // f[i] 表示从i到n 中 a[i]和 b[i] 中不同的个数
    for(int j = n-1; j >= 0; j--){
        f[j] = f[j + 1] + (a[j] != b[j]);
    }
    int pos = 0;
    for(int i = 0; i < n; i++){
        for(char ch = 'a'; ch <= 'z'; ch++){
            int now = pos;
            if(ch != a[i]) now++;
            if(ch != b[i]) now--;
            if(abs(now) > f[i + 1]) continue;
            // 如果f[i + 1]的个数 >= |NOW|那么可以通过后面的修改来抵消前面的修改
            cout << ch;
            if (ch != a[i]) pos++;
            if (ch != b[i]) pos--;
            break;
        }
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}