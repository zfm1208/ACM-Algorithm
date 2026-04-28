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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=" "+s;
    stack<int>s1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            s1.push(i);
        }
        else if(s[i]==')')
        {
            cout  << i << " " << s1.top() << " ";
            s1.pop();
        }
        else{
            cout << i << " ";
        }
    }

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