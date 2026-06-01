#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int n;
    cin >> n;
    int c1=0,c0=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        if(x%2)
        {
            c1++;
        }
        else
        {
            c0++;
        }
    }
    if(n==1)
    {
        if(c1%2)
        {
            cout << "Insight\n";
        }
        else
        {
            cout << "Maya\n";
        }
        return;
    }
    if(c0==0)
    {
        if(c1%2)
        {
            cout << "Insight\n";
        }
        else
        {
            cout << "Maya\n";
        }
        return;
    }
    if(c0%2)
    {
        cout << "Insight\n";
    }
    else
    {
        cout << "Maya\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}