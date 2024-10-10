/*
       sp,st,sp,sp
****** [0,6,0,0]
 *   * [1,3,1]
  *  * [1,2,1]
   * * [1,1,1]
    ** [2,0,0]
     * [5,1,0]

*/

#include<iostream>
using namespace std;
int main(){
    int n=6;
    for(int i=0;i<n;i++)
    {
        if(i==1||i==2||i==3)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<" ";
            }
            for(int k=0;k<1;k++)
            {
                cout<<"*";
            }
            for(int j=0;j<n-i-2;j++)
            {
                cout<<" ";
            }
            for(int k=0;k<1;k++)
            {
                cout<<"*";
            }
        }
        else
        {
            for(int j=0;j<i;j++)
            {
                cout<<" ";
            }
            
            for(int k=1;k<=n-i;k++)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }
}