#include <iostream>
#include <queue>
#include <string>
using namespace std;

void palindrom(string s) {
    queue<char>q1,q2;

    int m = s.length();
    for (int i = 0; i <m; i++) {
        q1.push(s[i]);
    }

    while (!q1.empty()) 
    {
        char c=q1.front();
        q1.pop();
        

        queue<char>temp;
        temp.push(c);

        while (!q2.empty()) {
            temp.push(q2.front());
            q2.pop();
        }

        q2 = temp;
    }
    string rev;
    while (!q2.empty()) {
        rev += q2.front();
        q2.pop();
    }

   if(rev==s){
       cout<<"palindrom"<<endl;
   }
   else{
       cout<<"not palindrom"<<endl;
   }
}

int main() 
{
    string s;
    cout <<"Enter string:";
    cin >>s;

    palindrom(s);
    return 0;
}
