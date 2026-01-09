#include<iostream>
using namespace std;
const int N=2e5+10;
int a[N],b[N],sum[5];
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int check(int x,int y){
    int t=gcd(x,y);
    x/=t;y/=t;
    if(x%2==0) return 0;
    if(y%2==0) return 1;
    return 2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int res;
        sum[0]=sum[1]=sum[2]=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0&&b[i]==0) continue;
            res=check(a[i],b[i]);
            sum[res]=1;
        }
        if(sum[0]+sum[1]+sum[2]<=1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}