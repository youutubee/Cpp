#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums1{ 1 , 3 };
    vector<int> nums2{ 2 };

        int i=0;
        int j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
            while(i<nums1.size()){
                ans.push_back(nums1[i]);
                i++;
            }
            while(j<nums2.size()){
                ans.push_back(nums2[j]);
                j++;
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
}