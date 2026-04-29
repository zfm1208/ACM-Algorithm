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
vector<int> e[105];
int h[105];
int d[105];
int ans[105][64];
int cnt0=0;

struct stt
{
    int cnt,jd;
}tr[105];


void dfs(int p,int jd)
{
    tr[p].jd=jd;
    if(jd==0)
    {
        cnt0++;
        tr[p].cnt=cnt0;
        for(int i=1;i<=59;i++)
        {
            if(i==cnt0)
            {
                ans[p][i]=0;
            }
            else
            {
                ans[p][i]=1;
            }
        }
    }
    for(int i=0;i<e[p].size();i++)
    {
        if(e[p][i]==h[p])continue;
        h[e[p][i]]=p;
        dfs(e[p][i],(jd+1)%2);
    }
}

void solve(){
    int n;
    cin >>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int g;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1)
        {
            g=i;
            break;
        }
    }
    h[g]=0;
    dfs(g,1); 
    for(int i=1;i<=n;i++)
    {
        if(tr[i].jd==1)
        {
            ans[i][60]=1;
            int x=tr[h[i]].cnt;
            ans[i][x]=1;
            for(int j=0;j<e[i].size();j++)
            {
                ans[i][tr[e[i][j]].cnt]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=60;j>=1;j--)
        {
            k=k*2+ans[i][j];
        }
        cout << k << " ";
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