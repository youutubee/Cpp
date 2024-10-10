#include<bits/stdc++.h>
using namespace std;
int main(){

    //inputs

    cout<<"Enter the string"<<endl;
    string s;
    cin>>s;
    cout<<"Enter the character to find"<<endl;
    char to_find;
    cin>>to_find;

    //main porgram

    int hash_arr[200]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        hash_arr[int(ch)]++;
    }
    cout<<hash_arr[int(to_find)];

}