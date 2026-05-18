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

void solve(){
    int n,k; cin >> n >> k;
    double p; cin >> p;
    map<pii, int> mp;
    int id = 0;
    for(int len = 0; len <= n; len++){
        for(int mask = 0; mask < (1 << len); mask++){
            if(__builtin_popcount(mask) < k){
                mp[{len, mask}] = ++id;
            }
        }
    }
    vector<vector<double>> A(id + 1, vector<double>(id + 2, 0.0));
    for(auto &[op, u]: mp){
        auto &[len, mask] = op;
        A[u][u] += 1.0;
        A[u][id+1] = 1.0;
        // 若开出0
        int mask0 = mask << 1;
        if(len == n){
            mask0 &= ((1 << n) - 1);
        }
        if(__builtin_popcount(mask0) < k){
            int v0 = mp[{min(n, len+1), mask0}];
            A[u][v0] -= (1.0 - p);
        }

        // 若开出1
        int mask1 = (mask << 1) | 1;
        if(len == n){
            mask1 &= ((1 << n) - 1);
        }
        if(__builtin_popcount(mask1) < k){
            int v1 = mp[{min(n, len+1), mask1}];
            A[u][v1] -= p;
        }
    }
    // 遍历主对角线每一列
    for(int i = 1; i <= id; i++){
        int pivot = i;
        // 找到绝对值最大的行并交换
        for(int j = i + 1; j <= id; j++){
            if (abs(A[j][i]) > abs(A[pivot][i])){
                pivot = j;
            }
        }
        swap(A[i], A[pivot]); 

        double diag = A[i][i];
        for (int j = i; j <= id + 1; j++) {
            A[i][j] /= diag;
        }

        for(int j = 1; j <= id; j++){
            if(i != j){
                double factor = A[j][i];
                for(int col = i; col <= id + 1; col++) {
                    A[j][col] -= factor * A[i][col];
                }
            }
        }
    }
    cout << fixed << setprecision(10) << A[mp[{0, 0}]][id + 1] << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}