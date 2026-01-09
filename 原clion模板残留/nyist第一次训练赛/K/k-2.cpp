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
int n;
void solve() {
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bool p = 0;
    for(int i = n; i >= 2; i--){
        if(a[i] != a[i-1]){
            p=1;
            int pos = i;
            if(a[i] > a[i-1]){
                for(int j = pos; j >= 2; j--){
                    if(a[j] < a[j-1]) {
                        cout << j-1 << endl;
                        return;
                    }
                }
                cout << 0 << endl;
                return;
            }else{
                bool f1 = 0;
                for(int j = pos; j >= 2; j--){
                    if(a[j] > a[j-1]){
                        f1 = 1;
                        for(int k = j-1; k >= 2; k--){
                            if(a[k] < a[k-1]){
                                cout << k-1 << endl;
                                return;
                            }
                        }
                        if(f1){
                            cout << 0 << endl;
                            return;
                        }
                    }
                }
                cout << 0 << endl;
                return;
            }
        }
    }
    if(!p) cout << 0 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
