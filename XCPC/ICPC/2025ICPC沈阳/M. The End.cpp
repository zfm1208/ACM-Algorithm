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
/*
    0 1 2 3 4 5 6 7

    0 1 2 3
    0 -> 2
    0 -> 3

    1 -> 2
    1 -> 3

            4 5 6 7
            4 -> 6
            4 -> 7

            5 -> 6
            5 -> 7


*/
void solve(){
    int n = 8;
    vector<int>a(n+1), b(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<vector<double>> w(n+1,vector<double>(n+1));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            w[i][j] = (double) a[i] * 1.0 / (a[i] + b[j]);
        }
    }
    vector<int> p(8);
    iota(p.begin(),p.end(),0);
    double ans = 0.0;

    do{
        double P[4][8] = {0};
        for(int i = 0; i < 8; i++) P[0][i] = 1.0;
        // 2 进 1
        for(int i = 0; i < 8; i+=2){
            int l = p[i], r = p[i+1];
            P[1][i] = P[0][i] * P[0][i+1] * w[l][r];
            P[1][i+1] = P[0][i] * P[0][i+1] * (1.0 - w[l][r]);
        }
        // 4 进 1
        for(int i = 0; i < 8; i += 4){
            for(int x = i; x <= i+1; x++){
                for(int y = i+2; y <= i+3; y++){
                    int l = p[x], r = p[y];
                    P[2][x] += P[1][x] * P[1][y] * w[l][r];
                    P[2][y] += P[1][y] * P[1][x] * (1.0 - w[l][r]);
                }
            }
        }
        // 8 进 1
        for(int x = 0; x <= 3; x++){
            for (int y = 4; y <= 7; y++){
                int l = p[x], r = p[y];
                P[3][x] += P[2][x] * P[2][y] * w[l][r];
                P[3][y] += P[2][y] * P[2][x] * (1.0 - w[l][r]);
            }
        }
        for(int i = 0; i < 8; i++){
            if(p[i] == 0){
                ans = max(ans, P[3][i]);
                break;
            }
        }
    }while(next_permutation(p.begin(),p.end()));
    cout << fixed << setprecision(15) << ans << endl;
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