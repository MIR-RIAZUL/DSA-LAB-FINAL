#include <iostream>
#include <stack>
#include <queue>
#define V 7

using namespace std;

void initialization(int arr[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][V], int src, int des)
{
    arr[src][des] = 1;
    arr[des][src] = 1;
}
void display(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << ":";
        for (int j = 0; j < V; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int arr[][V])
{
    bool visited[V] = {false};
    stack<int> st;

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
void bfs(int arr[][V])
{
    bool visited[V] = {false};
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i]=true;
            while (!q.empty())
            {
                int vertex = q.front();
                q.pop();
                cout << vertex << " ";
                for (int j = 0; j < V; j++)
                {
                    if (arr[vertex][j] == 1 && !visited[j])
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    int adjmatrix[V][V];
    initialization(adjmatrix);

    addEdge(adjmatrix, 0, 1);
    addEdge(adjmatrix, 1, 2);
    addEdge(adjmatrix, 3, 4);
    addEdge(adjmatrix, 5, 3);
    addEdge(adjmatrix, 2, 5);
    addEdge(adjmatrix, 4, 2);
    addEdge(adjmatrix, 4, 6);

    display(adjmatrix);

    cout << "dfs:";
    dfs(adjmatrix);
    cout << endl;
    cout << "bfs:";
    bfs(adjmatrix);
}