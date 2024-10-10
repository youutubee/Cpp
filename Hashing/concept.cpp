#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[9]={1,2,2,3,4,5,6,6,6};
    int hash_arr[10]={0};
    for(int i=0;i<9;i++){
        hash_arr[arr[i]]++;
    }
    cout<<hash_arr[6];    
}