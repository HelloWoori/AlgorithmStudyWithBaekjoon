/*
DFS와 BFS
https://www.acmicpc.net/problem/1260
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& check, int n);
void BFS(vector<vector<int>>& graph, vector<bool>& check, int n);

int main()
{
    ios_base::sync_with_stdio(false);

    int node = 0, edge = 0, start = 0;
    cin >> node >> edge >> start; 

    vector<vector<int>> graph(node + 1);
    vector<bool> check(node + 1, false);

    for (int i = 0; i < edge; ++i)
    {
        int node1 = 0, node2 = 0;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for (size_t i = 0; i < graph.size(); ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(graph, check, start);
    cout << '\n';

    check.clear();
    check.resize(node + 1, false);

    BFS(graph, check, start);
    cout << '\n';

    return 0;
}

void DFS(vector<vector<int>>& graph, vector<bool>& check, int n)
{
    cout << n << " ";
    check[n] = true;
    for (size_t i = 0; i < graph[n].size(); ++i)
    {
        int next = graph[n][i];
        if (check[next] == false)
        {
            DFS(graph, check, next);
        }
    }
}

void BFS(vector<vector<int>>& graph, vector<bool>& check, int n)
{
    queue<int> q;
    q.push(n);
    check[n] = true;

    while (q.empty() == false)
    {
        int front = q.front();
        cout << front << " ";
        q.pop();

        for (size_t i = 0; i < graph[front].size(); ++i)
        {
            int next = graph[front][i];
            if (check[next] == false)
            {
                q.push(next);
                check[next] = true;
            }
        }
    }
}