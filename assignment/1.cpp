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

       
        while (!tempStack.empty() && tempStack.top() < x)
        {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(x);
    }


    for(int i=0;i<n;i++)
    {
        cout<<tempStack.top()<<" ";
        tempStack.pop();
    }

    
    return 0;
}