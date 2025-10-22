#include <iostream>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T; // N = max size, T = number of operations

    int queue[N];
    int front = 0, rear = 0, size = 0;

    for (int i = 0; i < T; i++) {
        int op;
        cin >> op;

        if (op == 1) { // Enqueue
            if (size == N) {
                cout << "Queue is full!" << endl;
                continue;
            }
            int value;
            cin >> value;
            queue[rear] = value;
            rear = (rear + 1) % N;
            size++;
        } 
        else if (op == 2) { // Dequeue
            if (size == 0) {
                cout << "Queue is empty!" << endl;
                continue;
            }
            front = (front + 1) % N;
            size--;
        }

        // Print current state of queue
        cout << "size=" << size << " items=";
        if (size == 0) {
            cout << "NULL";
        } else {
            int count = size;
            int index = front;
            for (int j = 0; j < count; j++) {
                cout << queue[index] << " ";
                index = (index + 1) % N;
            }
        }
        cout << endl;
    }

    return 0;
}
