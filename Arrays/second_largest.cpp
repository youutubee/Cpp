#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Method ==>Sort the array first and then find the second largest element
Time complexity ==> O(N+N*logN) //NlogN for quick sort and an additional +N for the loop to find second largest 

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int partition_index=partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    quick_sort(arr,low,high);
    int largest=arr[n-1];
    int second_largest=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=largest){
            second_largest=arr[i];
            break;
        }
    }
    cout<<second_largest;
}

*/


/* 
Better approach ==> Time complexity ==>O(N+N)==>O(2N)

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    int second_largest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>second_largest && arr[i]<largest)
        {
            second_largest=arr[i];
        }
    }
    cout<<second_largest;

}

*/

//Optiomal Approach (Best approach) ==> fTime Complexity ==>O(N) ==>as there is only one loop to find both largest and the second largest

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=arr[0];
    int second_largest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        if(arr[i]>second_largest && arr[i]!=largest){
            second_largest=arr[i];
        }
    }
    cout<<second_largest;
}