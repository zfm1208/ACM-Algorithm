#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int qq[N]; 
void init(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            qq[j]++;
        }
    }
}
void solve(){
    int n,k; cin >> n >> k;
    vector<int> du(n+1);
    for(int i = 2; i <= n; i++){
        // int cnt = 0;
        // for(int x = 1; x*x <= i; x++){
        //     if(i % x == 0){
        //         du[x]++;
        //         cnt++;
        //         if(x * x != i && x != 1) {
        //             du[i/x]++; 
        //             cnt++;
        //         }               
        //     }
        // }
        // du[i] = cnt;
        du[i] = (qq[i] - 1) + (n / i - 1);
    }
    du[1] = n-1;
    // rep(i,1,n) cout << du[i] << " \n"[i==n];
    sort(du.begin()+1,du.end(),greater<int>());
    cout << du[k] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--)
        solve();
    return 0;
}