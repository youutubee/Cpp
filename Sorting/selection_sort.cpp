//Time complexity = O(n^2) for all cases

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minimum_index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[minimum_index]) minimum_index=j;
        }
        swap(arr[minimum_index],arr[i]);

        //just for better visualization
        cout<<"Array After step "<<i+1<<endl;
        print(arr,n);
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    cout<<"Final resultant array"<<endl;
    print(arr,n);
}