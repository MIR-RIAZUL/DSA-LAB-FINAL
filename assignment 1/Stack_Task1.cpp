#include <iostream>
using namespace std;

int main() {
    int n,m;
    cout<<"enetr the stack size:";
    cin>>n;
    int stack[n];
    int top=-1;
    cout<<"enter the number of operation:";
    cin>>m;
    while(m--)
    {
        cout<<"enter your operation:-"<<endl;
        cout<<"1.push number in the stack"<<endl;
        cout<<"2.pop a nuber from stack"<<endl;
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int a;
            cout<<"enter your value:";
            cin>>a;
            if(top<n-1)
            {
                stack[++top]=a;
            }
        }
        else if (ch==2)
        {
            if(top>=0)
            {
                top--;
            }
        }
        cout<<"size: "<<top+1<<", items: ";
        if(top==-1)
        {
            cout<<"NULL";
        }
        else 
        {
            for(int i=0;i<=top;i++)
            {
                cout<<stack[i]<<" ";
            }
        }
        cout<<endl;

    }
    return 0;
}
