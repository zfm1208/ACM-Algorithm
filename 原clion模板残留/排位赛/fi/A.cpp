//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int n;
void solve() {
    int n; cin >> n;
    while(n--){
        int ans;
        int a,b; cin >> a >> b;
        if(a == b) ans = 0;
        if(a > b){
            if((a-b)%2==0)ans=1;
            else {
                ans = 2;
            }
        }
        if(a < b){
            if((b-a)%2!=0)ans=1;
            else {
                int t = (b-a)/2;
                if(t%2!=0)ans = 2;
                else ans = 3;
            }
        }
        cout << ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}