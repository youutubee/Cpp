#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertsort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j > 0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    print(arr,7);

}

int main(){
    int arr[7]={9,5,3,8,1,5,2};
    insertsort(arr,7);
}