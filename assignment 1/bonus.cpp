#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int N;
    cout <<"Enter number  students:";
    cin>>N;

    queue<int>student;
    stack<int>sandwiche;

    cout << "Enter student preferences (0 =circular, 1 =square): ";
    for (int i = 0; i < N; i++)
    {
        int prf;
        cin >> prf;
        student.push(prf);
    }

    cout << "Enter sandwiche(0=circular,1=square):";
    int arr[N];
    for (int i = 0; i <N; i++)
        cin >> arr[i];

    for (int i=N -1; i>= 0; i--)
        sandwiche.push(arr[i]);

    int count = 0;

    while (!student.empty() && count<student.size())
    {
        int frontStudent=student.front();
        int topSandwich=sandwiche.top();

        if (frontStudent==topSandwich)
        {

            student.pop();
            sandwiche.pop();
            count = 0;
        }
        else
        {

            student.pop();
            student.push(frontStudent);
            count++;
        }
    }

    cout << "Number of students unable to eat: " << student.size() << endl;

    return 0;
}
