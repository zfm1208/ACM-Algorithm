//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
//#define pb push_back
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int nb,ns,nc,pb,ps,pc;
map<char,int> mp;
string S;
int w;
bool check(int mid){
    int sum = 0;
    if(mid * mp['B'] > nb) sum += (mid * mp['B'] - nb) * pb;
    if(mid * mp['S'] > ns) sum += (mid * mp['S'] - ns) * ps;
    if(mid * mp['C'] > nc) sum += (mid * mp['C'] - nc) * pc;
    return sum <= w;
}
void solve() {
    cin >> S;;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> w;
    rep(i,0,S.size()) mp[S[i]]++;
    int l = 0,r = w + max(nb, max(nc, ns));
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
