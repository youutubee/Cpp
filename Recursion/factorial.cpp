#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}
int main(){
    int ans=factorial(3);
    cout<<ans;
} 