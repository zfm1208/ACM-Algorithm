//
// Created by zfm25 on 2025/4/5.
//
#include<bits/stdc++.h>
char s[100005],t[100005];
using namespace std;
int main(){
    int n,p1,p2,l;
    cin >> n;
    scanf("%s",s+1);
    strcpy(t+1,s+1);
    cin >> p1 >> p2 >> l;
    for(int i=0;i<l;i++)t[p2+i]=s[p1+i];
    for(int i=0;i<l;i++)s[p2+i]=s[p1+i];
    for(int i=1;i<=n;i++) cout << s[i];
    cout << endl;
    for(int i=1;i<=n;i++) cout << t[i];
}
//#include<iostream>
//#include<algorithm>
//#define int long long
//using namespace std;
//const int N=1e5+10;
//char a[N],b[N];
//
//
//void solve()
//{
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    s=" "+s;
//    int p1,p2,l;
//    cin >> p1 >> p2 >> l;
//    a[0]=' ';
//    b[0]=' ';
//    if(p1!=p2){
//        for(int i=1;i<=n;i++){
//            a[i]=s[i];
//            b[i]=s[i];
//        }
//        for(int i=p2;i<p2+l;i++){
//            a[i]=a[i-p2+p1];
//            b[i]=s[i-p2+p1];
//        }
//        for(int i=1;i<=n;i++){
//            cout << a[i];
//        }
//        cout << '\n';
//        for(int i=1;i<=n;i++){
//            cout << b[i];
//        }
//        cout << '\n';
//    }
//    else{
//        for(int i=1;i<=n;i++){
//            cout << s[i];
//        }
//        cout << '\n';
//        for(int i=1;i<=n;i++){
//            cout << s[i];
//        }
//        cout << '\n';
//    }
//}
//
//signed main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(0),cout.tie(0);
//    int t=1;
////	cin >> t;
//    while(t--)solve();
//}