#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    arr.push_back(1);  
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    vector<int> ans(arr.size());     
    stack<int> s;

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}






