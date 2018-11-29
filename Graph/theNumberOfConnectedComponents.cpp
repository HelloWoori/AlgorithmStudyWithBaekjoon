/*
연결 요소의 개수 
https://www.acmicpc.net/problem/11724
*/
#include <iostream>
#include <vector>

using namespace std;

#define TRUE  1
#define FALSE 0

void dfs(int x, const vector<vector<int>> &graph, vector<int> &check)
{
    check[x] = TRUE;

    for (size_t i = 0; i < graph[x].size(); ++i)
    {
        int nextNode = graph[x][i];
        if (check[nextNode] == FALSE)
        {
            check[nextNode] = TRUE;
            dfs(nextNode, graph, check);
        }
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
 
    int node, edge;
    cin >> node >> edge;

    vector<vector<int>> graph(node + 1);
    vector<int> check(node + 1, FALSE);

    //인접리스트 생성
    for (int i = 0; i < edge; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    //연결요소 구하기
    int connectedComponent = 0;
    for (int i = 1; i <= node; ++i)
    {
        if (check[i] == FALSE)
        {
            dfs(i, graph, check);
            connectedComponent += 1;
        }
    }

    cout << connectedComponent << '\n';

    return 0;
}