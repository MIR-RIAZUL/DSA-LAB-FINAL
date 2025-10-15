#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        // Push opening brackets to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        else {
            // If stack is empty, invalid
            if (st.empty()) return false;

            // Check matching pairs
            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    // Stack should be empty if all brackets matched
    return st.empty();
}

int main() {
    string s;

    cout << "Enter brackets string: ";
    cin >> s;

    if (isValid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
