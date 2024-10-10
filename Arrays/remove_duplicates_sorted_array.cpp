//This is the most optimal approach Time complexity =>O(N) 

//Two Pointer Approach

#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&ans)
{
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

void remove_duplicates(int arr[],int n){
    int i=0;
    vector<int>ans;
    ans.push_back(arr[i]);
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            ans.push_back(arr[j]);
            i=j;      
        }
    }
    print(ans);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    remove_duplicates(arr,n);    
}