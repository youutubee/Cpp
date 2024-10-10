/*

  *
 ***
*****
 ***
  *


*/

#include<iostream>
using namespace std;
int main()
{
    int n=5;
    
    int mid=n/2;

    //for upper part of the diamond

    for(int i=0;i<=mid;i++)
    {
        for(int j=0;j<mid-i;j++)
        {
            cout<<" ";
        }
        for(int k=1;k<=(2*i+1);k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    //for lower part of the diamond

    for(int i=mid-1;i>=0;i--)
    {
        for(int j=0;j<mid-i;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}