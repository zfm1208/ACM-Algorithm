#include<iostream>
#include<vector>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define pi acos(-1.0)
#define se second
#define fi first
#define endl '\n'
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 10001;
int n;
vector<int> prime;
bool vis[N];
void get_prime(){
    rep(i,2,10000){
        if(!vis[i]){
            prime.pb(i);
            for(int j = i * i; j <= 10000; j += i) vis[j] = 1;
        }
    }
}
void solve() {
    get_prime();
    while(cin >> n && n != 0){
        int cnt = 0, sum = 0;
        int l = 0, r = 0;
        while(r < prime.size()){
            if(sum + prime[r] <= n){
                sum += prime[r];
                r++;
            }else{
                sum -= prime[l];
                l++;
            }
            if(sum == n)cnt++;
        }
        cout << cnt << endl;
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