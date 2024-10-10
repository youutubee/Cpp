#include<bits/stdc++.h>
using namespace std;
int power(int n){
    if(n==1) return 2;
    return 2*power(n-1);
}
int main(){
    int ans=power(4);
    cout<<ans;
}