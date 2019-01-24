/*
DFS와 BFS
https://www.acmicpc.net/problem/1260
- https://www.acmicpc.net/board/view/27472 (문제풀때 주의해야할 점)
- https://www.acmicpc.net/board/view/24356 (추가 예제)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define TRUE  1
#define FALSE 0

void dfs(const int x, const vector<set<int>> &graph, vector<size_t> &check)
{
    check[x] = TRUE; //방문했다
    cout << x << ' ';
    for(auto it = graph[x].begin(); it != graph[x].end(); ++it)
    {
        int next = *it;
        if (check[next] == FALSE)
        {
            dfs(next, graph, check);
        }
    }
}

void bfs(const int x, const vector<set<int>> &graph, vector<size_t> &check)
{
    queue<int> q;
    check[x] = TRUE; //방문했다
    q.push(x);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << ' ';

        for (auto it = graph[front].begin(); it != graph[front].end(); ++it)
        {
            int next = *it;
            if (check[next] == FALSE)
            {
                check[next] = TRUE;
                q.push(next);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int node, edge, startNode;
    cin >> node >> edge >> startNode;

    vector<set<int>> graph(node + 1);  //정점은 1번부터
    vector<size_t> check(node + 1, FALSE); //방문한 노드인지 체크여부
    
    //인접 리스트 생성
    for (int i = 0; i < edge; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1].insert(n2);
        graph[n2].insert(n1);
    }

    dfs(startNode, graph, check);

    check.clear();
    check.resize(node + 1, FALSE);
    cout << '\n';

    bfs(startNode, graph, check);
    cout << '\n';

    return 0;
}