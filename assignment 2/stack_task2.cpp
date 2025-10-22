#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter numbr of element:";


    cin >>n;

    vector<int> arr(n);

    cout <<"Enter "<<n<<"elements:";

    for (int i=0;i<n;i++)
    {

        cin >> arr[i];
    }
    vector<int>gn(n,-1);



    stack<int>st;

    for (int i=n-1;i>=0;i--){

        while(!st.empty()&& st.top()<arr[i])
        {

            st.pop();

        }


        if (!st.empty()) 
        {

            gn[i] = st.top();
        }

        st.push(arr[i]);
    }

    cout <<"next greater elemnt:";


    for (int i=0;i<n;i++)
    {
        cout<<gn[i]<<" ";
    }
    cout << endl;

    return 0;
}
