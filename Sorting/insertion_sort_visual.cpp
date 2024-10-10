//Recommened ==> Please give this program different cases and visually see them running to get a better idea

//Time Complexity ==> O(n^2) ==> Worst and Average case
//Time Complexity ==> O(n) ==>for best case (Already sorted array) because the inner while loop dosent runs even one time


#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<=n-1;i++)         
    {
        int j=i;

        cout<<"Array before going through step "<<i<<" Value of arr[j] here is "<<arr[j]<<endl;
        print(arr,n);
        cout<<endl;
        while(j>0 && arr[j-1]>arr[j])
        {
            cout<<"Before Part "<<i-j+1<<" of step "<<i<<endl;
            print(arr,n);
            cout<<endl;
            swap(arr[j],arr[j-1]);
            cout<<"After Part "<<i-j+1<<" of step "<<i<<endl;
            print(arr,n);
            cout<<endl;
            j--;
        }
        cout<<"Array after going through step "<<i<<endl;
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
    insertion_sort(arr,n);
    cout<<"Resultant sorted array"<<endl;
    print(arr,n);
}