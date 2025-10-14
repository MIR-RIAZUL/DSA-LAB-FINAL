#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> inputStack, tempStack;

    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        inputStack.push(x);
    }


    while (!inputStack.empty())
    {
        int x = inputStack.top();
        inputStack.pop();

       
        while (!tempStack.empty() && tempStack.top() > x)
        {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(x);
    }

    stack<int> output;
    while (!tempStack.empty())
    {
        output.push(tempStack.top());
        tempStack.pop();
    }

    while (!output.empty())
    {
        cout << output.top() << " ";
        output.pop();
    }
    return 0;
}