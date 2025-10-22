#include <iostream>

#include <queue>

using namespace std;

void revrse(string s)

{

    queue<char> q_1, q_2;

    int m = s.length();

    for (int i = 0; i < m; i++)

    {

        q_1.push(s[i]);
    }

    while (!q_1.empty())

    {

        char c = q_1.front();

        q_1.pop();

        queue<char> temp;

        temp.push(c);

        while (!q_2.empty())

        {

            temp.push(q_2.front());

            q_2.pop();
        }

        q_2 = temp;
    }

    string rev;

    while (!q_2.empty())

    {

        rev += q_2.front();

        q_2.pop();
    }

    if (rev == s)
    {

        cout << "palindrom" << endl;
    }

    else
    {

        cout << "not palindrom" << endl;
    }
}

int main()

{

    string s;

    cout << "Enter string:";
    cin>>s;

    revrse(s);

    return 0;
}