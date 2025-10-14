#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> inputStack, tempStack;

    // Read input numbers
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        inputStack.push(x);
    }

    // Sort using stacks
    while (!inputStack.empty()) {
        int x = inputStack.top();
        inputStack.pop();

        // Move elements back if they are greater than current x
        while (!tempStack.empty() && tempStack.top() > x) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(x);
    }

    // Output in ascending order
    stack<int> outputStack;
    while (!tempStack.empty()) {
        outputStack.push(tempStack.top());
        tempStack.pop();
    }

    while (!outputStack.empty()) {
        cout << outputStack.top() << " ";
        outputStack.pop();
    }

    return 0;
}
