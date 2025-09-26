#include<iostream>
using namespace std;

int main(){
    int n = 5;
// for(int i=1; i<=n; i++) {
//     for(int j=1; j<=n-i; j++) {
//     cout << " ";
//     }
//     for(int j=i; j>=1; j--) {
//     cout << j;
//     }
//     for(int j=2; j<=i; j++) {
//     cout << j;
//     }
// cout << endl;
// }
bool val = true;
for(int  i=0;i<=n;i++){
    if(i%2==0){
            val=true;
        }
    for(int j=0;j<=i;j++){
        
        cout<<val<<" ";
        val =! val;


    }
    cout<<endl;
}



     return 0;
}