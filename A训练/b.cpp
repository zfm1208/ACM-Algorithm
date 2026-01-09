#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3fLL
int a[2005];
int ai[2005][2005];
stack<int>s;
int main(){
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mn = INF;
    for (int i = 1; i <= n; i++){
        ai[i][i] = a[i];
        if (a[i] == 1) {mn = 1; break;}
        for (int j = i + 1; j <= n; j++){
            ai[i][j] = __gcd(ai[i][j - 1], a[j]);
            if (ai[i][j] == 1) mn = min(mn, j - i + 1);
        }
    }
    int cnt = 0;
    if (mn == 1){
        for (int i = 1; i <= n; i++){
            if (a[i] != 1) cnt++;
        }
    }
    else{
        cnt = n + mn - 2;
    }
    if (mn == INF) cnt = -1;
    cout << cnt << '\n';
    return 0;
}
