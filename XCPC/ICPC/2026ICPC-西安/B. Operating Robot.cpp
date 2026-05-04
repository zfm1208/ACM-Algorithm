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
    int n,x,y; 
    cin >> n >> x >> y;
    string s; cin >> s;
    s = " " + s;
    if(x + y <= n){
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= x+y; i++){
            if(s[i] == '0') cnt0++; // 向右
            else if(s[i] == '1') cnt1++; // 向上
            else if(s[i] == '2') cnt2++;
        }
        if(cnt0 > x || cnt1 > y){
            cout << -1 << endl;
            return;
        }
        int qian = (x - cnt0);
        for(int i = 1; i <= x+y; i++){
            if(s[i] == '1') cout << 1;
            else if(s[i] == '0') cout << 0;
            else {
                if(qian) {
                    cout << 0;
                    qian--;
                }else{
                    cout << 1;
                }
            }
        }
        for(int i=x+y+1; i <= n; i++){
            if(s[i] == '1') cout << 1;
            else if(s[i] == '0') cout << 0;
            else {
                cout << 0 ;
            }
        }
        cout << endl;
    }else{
        int a=(x+y)/n;
        int r=(x+y)%n;
        int x1=0;
        int x0=0;
        int x2=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                x1++;
            }
            else if(s[i]=='0')
            {
                x0++;
            }
            else 
            {
                x2++;
            }
        }
        int k=y-a*x1;
        int qx2=0;
        for(int i=1;i<=r;i++)
        {
          if(s[i]=='1')
          {
          k--;
          }
          else if(s[i]=='2')
          {
            qx2++;
          }
        }
        int hx2=x2-qx2;
        int yy=k%a;
        int yyy=(k-yy)/a-yy;
        if(qx2>=yy&&hx2>=yyy)
        {
           
            for(int i=r;i>=1;i--)
            {
                if(s[i]=='2'&&yy>0)
                {
                    yy--;
                    s[i]='1';
                }
                else if(s[i]=='2') 
                {
                s[i]='0';
                }
            }
             for(int i=n;i>r;i--)
            {
                if(s[i]=='2'&&yyy>0)
                {
                    yyy--;
                    s[i]='1';
                }
                else if(s[i]=='2') 
                {
                s[i]='0';
                }
            }
            int xx=0;
            int yy=0;
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='0')
                {
                    xx++;
                }
                else
                {
                    yy++;
                }
            }
            xx*=a;
            yy*=a;
             for(int i=1;i<=r;i++)
            {
                 if(s[i]=='0')
                {
                    xx++;
                }
                else
                {
                    yy++;
                }
            }
            if(xx!=x||yy!=y)
            {
                cout<<-1<<'\n';
                return;
            }
            for(int i=1;i<=n;i++)
            {
                cout<<s[i];
            }
            cout<<'\n';
            return;
        }
        else 
        {
            for(int i=hx2;i>=0;i--)
            {
                if((k-i*a)%(a+1)==0&&(k-i*a)/(a+1)<=qx2)
                {
            yyy=i;
            yy=(k-i*a)/(a+1);
            for(int i=r;i>=1;i--)
            {
                if(s[i]=='2'&&yy>0)
                {
                    yy--;
                    s[i]='1';
                }
                else if(s[i]=='2') 
                {
                s[i]='0';
                }
            }
             for(int i=n;i>r;i--)
            {
                if(s[i]=='2'&&yyy>0)
                {
                    yyy--;
                    s[i]='1';
                }
                else if(s[i]=='2') 
                {
                s[i]='0';
                }
            }
            int xx=0;
            int yy=0;
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='0')
                {
                    xx++;
                }
                else
                {
                    yy++;
                }
            }
            xx*=a;
            yy*=a;
            for(int i=1;i<=r;i++)
            {
                 if(s[i]=='0')
                {
                    xx++;
                }
                else
                {
                    yy++;
                }
            }
            if(xx!=x||yy!=y)
            {
               continue;
            }
            for(int i=1;i<=n;i++)
            {
                cout<<s[i];
            }
            cout<<'\n';
            return;
            }
        }
        cout<<-1<<'\n';
        return;
        }
        
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