#include <iostream>
using namespace std;

int main()
{
    cout<<"enter max size and number of operations"<<endl;
    int msize, nops;
    cin>>msize>>nops;

    int queue[msize];
    int front = -1, rear = -1, size = 0;

    for(int i=0;i<nops;i++)
{
    cout<<"enter the operation(1==enqueue, 2==dequeue)"<<endl;

    int opo;
    cin>>opo;
    if(opo==1) //enqueue
    {
        if(size==msize)
        {
            cout<<"Queue is full!"<<endl;
            continue;
        }
        cout<<"enter the value "<<endl;

        int val;
        cin>>val;
        queue[rear]=val;
        rear=(rear+1)%msize;
        size++;

}
else if (opo==2)
{
    if(size==0)
    {
        cout<<" empty queue"<<endl;
        continue;
    }
    front=(front+1)%msize;
    size--;
}
cout<<"size="<<size<<" items= ";
if(size==0)
{
    cout<<"null";
}
else
{
    int count=size;
    int i=front;
    for(int j=0;j<count;j++)
    {
        cout<<queue[i]<<" ";
        i=(i+1)%msize;
    }

}
}
    return 0;
}