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
    double atk=0;
    double atkr = 0.0;
    double cr = 5.0;
    double cdr = 50.0;
    for(int i = 1; i <= 25; i++){
        string s; 
        getline(cin,s);
        if(s[0]=='A'&&s[1]=='T'&&s[2]=='K'&&s[3]=='+'){
            string t;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '+'){
                    for(int k = j+1; k < s.size(); k++){
                        t += s[k];
                    }
                    break;
                }
            }
            double ans = stod(t);
            // cout<<t<<'\n';
            // cout << i << " " << ans << endl;
            atk += ans;
        }
        else if(s.substr(0,8) == "ATK Rate"){
            string t;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '+'){
                    for(int k = j+1; k < s.size() - 1; k++){
                        t += s[k];
                    }
                    break;
                }
            }
            double ans = stod(t);
            atkr += ans;            
        }
        else if(s.substr(0,9) == "Crit Rate"){
            string t;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '+'){
                    for(int k = j+1; k < s.size() - 1; k++){
                        t += s[k];
                    }
                    break;
                }
            }
            double ans = stod(t);
            cr += ans;              
        }
        else if(s.substr(0,8) == "Crit DMG"){
            string t;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '+'){
                    for(int k = j+1; k < s.size() - 1; k++){
                        t += s[k];
                    }
                    break;
                }
            }
            double ans = stod(t);
            cdr += ans;   
        }
    }
    // cout << atk << " " << atkr << " " << cr << " " << cdr << endl;
    if(cr >= 100) cr = 100.0;
    double atk1 = 1500*(1+atkr*1.0/100) + atk;
    // cout << atk1 << endl;
    double E;
    E = atk1 * 1.0 * (1.0 - cr*1.0/100) + atk1 * 1.0 *  (1.0 + cdr *1.0 / 100) * (cr * 1.0 / 100);
    cout << fixed << setprecision(10) << E << endl;
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