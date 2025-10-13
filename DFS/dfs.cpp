#include <iostream>
#include <stack>
#define V 6
using namespace std;

void initialize(int arr[][V])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = 0;
}

// Create an edge src <-> des (undirected)
void addEdge(int arr[][V], int src, int des)
{
    arr[src][des] = 1;
    arr[des][src] = 1;
}

void display(int arr[][V])
{
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < V; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs(int arr[V][V])
{
    bool visited[V] = {false};
    stack<int> st;

    cout << "DFS Traversal: ";

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            st.push(i);
            while (!st.empty())
            {
                int vertex = st.top();
                st.pop();

                if (!visited[vertex])
                {
                    visited[vertex] = true;
                    cout << vertex << " ";

                    // Push adjacent vertices in reverse order
                    for (int j = V - 1; j >= 0; j--)
                    {
                        if (arr[vertex][j] == 1 && !visited[j])
                        {
                            st.push(j);
                        }
                    }
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    int adjMatrix[V][V];
    initialize(adjMatrix);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 3, 5);
    addEdge(adjMatrix, 4, 3);

    display(adjMatrix);
    dfs(adjMatrix);

    return 0;
}
