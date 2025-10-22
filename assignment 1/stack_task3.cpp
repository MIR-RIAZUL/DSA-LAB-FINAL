#include <iostream>
#include <stack>
using namespace std;

void isvalid(string sr)
{
    stack<char>stack;
    int sz=sr.size();
    for(int i=0;i<sz;i++)
    {
        if(sr[i]=='(' || sr[i]=='{' || sr[i]=='[')
        {
            stack.push(sr[i]);
        }
        else 
        {
            if(stack.empty())
            {
                cout<<"false"<<endl;
                return;
            }
            char Top=stack.top();
            stack.pop();
            if((sr[i]==')' && Top!='(') || (sr[i]=='}' && Top!='{') || (sr[i]==']' && Top!='['))
            {
                cout<<"false"<<endl;
                return;
            }
            else

            {
                cout<<"true"<<endl;
                return;
            }
        }
    }
}


int main()
{
    string sr;
    cout<<"enter the string of bracket:";
    cin>>sr;
    isvalid(sr);
    return 0;
}