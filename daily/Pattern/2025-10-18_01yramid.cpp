
#include<iostream>
using namespace std;
int main(){
    int n = 5;
    bool val = true;
    for(int i=0;i<=n;i++){
        if(i%2==0){
        val = true;
        }
    for(int j=0;j<=i;j++){
        cout<<val<<" ";
        val =! val;
    }
    cout<<endl; 
    }
    return 0;
}
