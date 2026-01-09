#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
signed main(){
    int t;cin>>t;
    while(t--){
        int k;
        cin>>k;//第 k 个数字
        int m=1;
        while(1){
            if(m*2<=k){
                k++;
                m=m*2;
            }else{
                break;
            }
        }
        cout<<2*k<<"\n";

    }
    return 0;
}