#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        if(k % 3 == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}