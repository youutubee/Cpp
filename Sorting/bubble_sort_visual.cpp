//Recommened ==> Please give this program different cases and visually see them running to get a better idea

//Time Complexity ==> O(n^2) ==> Worst and Average case
//Time Complexity ==> O(n) ==>for best case (Already sorted array) because of the optimization we made
//if the array is already sorted we break the loop so it just runs for 1 time form 0 to n so O(n)


#include<bits/stdc++.h>
using namespace std;

void print(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubble_sort(int arr[] , int n){

    //for optimization if the array is already sorted no swaps would happen and the count will remain at 0;

    int swaps=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j+1],arr[j]);
                swaps++;
            }
            cout<<"Array after step "<<j+1<<" of "<<i+1<<endl;
            print(arr,n);
            cout<<endl;
        }
        //if condition to check if there hasnt been any swaps it means the array is sorted so we break out
        if(swaps==0){
            break;
        }
        cout<<"Array after step "<<i+1<<endl;
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
    bubble_sort(arr,n);
    cout<<"Resultant sorted array"<<endl;
    print(arr,n);
}

