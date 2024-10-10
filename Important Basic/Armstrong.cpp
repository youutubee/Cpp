#include<bits/stdc++.h>
using namespace std;
bool isArmstrong(int num)
{
    int num2=num;
    int sum=0;
    while(num)
    {
        int last_digit=num%10;
        sum=sum+(last_digit*last_digit*last_digit);
        num=num/10;
    }
    if(num2==sum) return true;
    else return false;
}
int main(){
    int num;
    cout<<"Enter number ";
    cin>>num;
    bool ans=isArmstrong(num);
    cout<<ans;
}
