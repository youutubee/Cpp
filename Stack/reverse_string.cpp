#include<bits/stdc++.h>
using namespace std;

/*
reverse string using a stack.

Here's what we'll do:
1. We'll ask you to type in a string.
2. We'll then use a stack to help us reverse the string. Think of a stack like a stack of plates: you put one on top of another, and when you take them off, you start from the top.
3. We'll push each letter of the string onto our stack of plates.
4. After that, we'll take each letter off the stack and put it into a new string. Because we're taking the letters off in the opposite order, the new string will be the reverse of the original one.
5. Finally, we'll show you the reversed string. Ready? Let's do this!
*/

int main() {
    // Step 1: Ask for a string input
    string str;
    cout << "Type a string and press enter: ";
    cin >> str;
    
    // Step 2: Create a stack to hold our characters
    stack<char> c;
    
    // Step 3: Push each character of the string onto the stack
    // Imagine we're putting each letter on top of the previous one
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        c.push(ch);
    }
    
    // Step 4: Create a new string to store the reversed version
    string ans = "";
    
    // Step 5: Pop each character from the stack and add it to the new string
    // We're taking the letters off the stack starting from the top, so it's in reverse order
    while(!c.empty()) {
        ans.push_back(c.top()); // Get the top letter
        c.pop(); // Remove the top letter from the stack
    }
    
    // Step 6: Show the reversed string
    cout << "The reversed string is: " << ans;
}
