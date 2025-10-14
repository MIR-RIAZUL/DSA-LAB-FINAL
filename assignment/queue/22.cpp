#include<iostream>
#include<queue>
using namespace std;


int main()
{
    string str;
    cin>>str;
    queue<int>q;
    for(char ch:str)
    {
        q.push(ch);
    }

        bool palingdrome=true;
        int n=str.length();
        for(int i=n-1;i>=0;i--)
        {
            if(q.front() !=str[i])
            {
                palingdrome=false;
                break;
            }
            q.pop();
        }

        if(palingdrome)
        {
            cout<<"palingdrome"<<endl;
        }
        else
        {
            cout<<"not"<<endl;
        }
}


