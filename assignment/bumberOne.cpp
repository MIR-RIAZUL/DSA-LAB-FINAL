#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cin >> str;
    queue<char> q;

    // Put all characters in the queue
    for (char ch : str) q.push(ch);

    bool palindrome = true;
    int n = str.length();

    // Check palindrome
    for (int i = n - 1; i >= 0; i--) {
        if (q.front() != str[i]) {
            palindrome = false;
            break;
        }
        q.pop();
    }

    if (palindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
