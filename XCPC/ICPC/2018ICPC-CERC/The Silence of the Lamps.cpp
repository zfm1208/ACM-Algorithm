#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9+7;
int cf[N+5];
void init(){
    for(int i=1;i<=100;i++)
    {
        for(int j=i+1;j<sqrt(N/i);j++)
        {
            for(int k=j+1;k<=N/i/j;k++)
            {
                cf[i*j*k]++;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        cf[i]=cf[i-1]+cf[i];
    }
}

void solve(){
    int n; cin >> n;
    int ans = 0;

    cout << cf[n] << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    init();
    while(T--){
        solve();
    }
    return 0;
}