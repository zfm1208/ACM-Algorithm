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
string s;
int n;
int b[10];
int ans;
void dfs(int k,int cs)
{
    if(cs==k+1)
    {
        string s2=s;
        for(int i=1;i<cs;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[j]=='1')
                {
                    if(j+b[i]<n)
                    {
                        s2[j+b[i]]='1';
                    }
                    
                }
            }
        }
        int sf=1;
        for(int i=0;i<n;i++)
        {
            if(s2[i]=='0')
            {
                sf=0;
                break;
            }
        }
        if(sf)
        {
            ans=sf;
        }
        return;
    }
    for(int i=1;i<=20;i++)
    {
        b[cs]=i;
        dfs(k,cs+1);
    }
}
void solve(){
    cin >> s;
    if(s[0]=='0')
    {
        cout << "-1\n";
        return;
    }
    n=s.size();
    int jl=0;
    for(int i=0;i<=7;i++)
    {
        dfs(i,1);
       
        if(ans!=0)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1" << '\n';
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
