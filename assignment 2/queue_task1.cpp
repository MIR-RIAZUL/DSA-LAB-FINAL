#include<iostream>
#include<queue>

using namespace std;

void pillowpassingwinner(int n,int m)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        q.push(i);
    }
    while(q.size()>1)
    {
        for(int i=0;i<m-1;i++)
        {
           int c= q.front();
            q.pop();
            q.push(c);
        }
        int r=q.front();
        q.pop();
    }

    cout<<"the winner is:"<<q.front()+1<<endl;
}

int main()
{
    cout<<"enter the umber of the person:";
    int x;
    cin>>x;
    cout<<"enter the traversal of pillow:";
    int m;
    cin>>m;

    pillowpassingwinner(x,m);

}