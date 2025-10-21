#include<iostream>
#include<stack>
using namespace std;

bool palindrome(string s)
{
    stack<int>st;
    int n=s.length();

    for(int i=0;i<n;i++)
    {
        st.push(s[i]);
    }
    string reverse;
    while(!st.empty())
    {
        reverse+=st.top();
        st.pop();
    }
    return s==reverse;
}

int main()
{
    int n;
    cout<<"how many times you want to test:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"enter the word:";
        string s;
        cin>>s;
        if(palindrome(s))
        {
            cout<<"yes"<<endl;
        }
        else 
        {
            cout<<"no"<<endl;
        }
    }

}