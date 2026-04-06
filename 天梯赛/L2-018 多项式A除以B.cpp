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
    int n; cin >> n;
    vector<double> A(N);
    int maxA = 0,maxB = 0;
    while(n--){
        int e; double c;
        cin >> e >> c;
        A[e] = c;
        maxA = max(maxA,e);
    }
    cin >> n;
    vector<double> B(N);
    while(n--){
        int e; double c;
        cin >> e >> c;
        B[e] = c;
        maxB = max(maxB,e);
    }    
    vector<double> Q(N); 
    while(maxA >= maxB){
        double c = A[maxA] / B[maxB];
        int e = maxA - maxB;
        Q[e] = c;
        for(int i = maxB; i >= 0; i--){
            A[i+e] -= c * B[i];
        }
        while(maxA >= 0 && abs(A[maxA]) < 1e-6){
            maxA--;
        }        
    }
    vector<double> R(maxA+1);
    for (int i = 0; i <= maxA; i++) {
        R[i] = A[i];
    }
    auto sc = [&] (vector<double>& s) -> void {
        int cnt = 0;
        vector<pair<int, double>> ans;
        for(int i = s.size() - 1; i >= 0; i--){
            if(abs(s[i]) >= 0.05) {
                ans.pb({i, s[i]});
            }
        }
        if(ans.empty()) {
            cout << "0 0 0.0" << endl;
        }else{
            cout << ans.size();
            for(auto [x,y] : ans){
                cout << " " << x << " " << fixed << setprecision(1) << y;
            }
            cout << endl;
        }
    };
    sc(Q);
    sc(R);
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