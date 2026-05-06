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
    string s;
    cin >> s;
    if(s[0]=='0')
    {
        cout << "-1\n";
        return;
    }
    int n=s.size();
    int cnt=0;
    while(cnt<5)
    {
       
        int sf=0;
        int pp=0,mx=n;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(pp){
                    mx=min(mx,pp);
                }
                sf=1;
                pp=0;
            }
            else
            {
                pp++;
                // mx=max(mx,pp);
            }
        }
        if(pp){
            mx=min(mx,pp);
        }
        int cc=0;
        // for(int i=n-1;i>=1;i--)
        // {
        //     if(s[i]=='0')
        //     {
        //         cc++;
        //     }
        // }
        // mx=min(mx,cc);
        if(!sf)
        {
            break;
        }
        // cout << mx << " ";
        string s2=s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                if(i+mx<n)
                {
                    s2[i+mx]='1';
                }
                
            }
        }
        s=s2;
         cnt++;
        // cout << s << " ";
    }
    cout << cnt << '\n';
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