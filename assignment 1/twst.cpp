#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // To ignore newline after integer input

    for (int i = 0; i < N; i++) {
        string str;
        getline(cin, str);

        queue<char> q1, q2;

        // Enqueue all characters of the string into q1
        for (char ch : str) {
            q1.push(ch);
        }

        // Reverse using another queue (q2)
        while (!q1.empty()) {
            char ch = q1.back(); // Get last element logic not possible directly
            // So we transfer all except last to another temp queue
            queue<char> temp;
            while (q1.size() > 1) {
                temp.push(q1.front());
                q1.pop();
            }
            char last = q1.front();
            q1.pop();
            q2.push(last);
            q1 = temp; // Move temp back into q1
        }

        // Print reversed string
        while (!q2.empty()) {
            cout << q2.front();
            q2.pop();
        }
        cout << endl;
    }

    return 0;
}
