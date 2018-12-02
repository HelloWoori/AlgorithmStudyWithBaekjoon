/*
이분 그래프
https://www.acmicpc.net/problem/1707
- https://www.acmicpc.net/board/view/28396 (문제풀때 주의해야할 점)
- https://www.acmicpc.net/board/view/8508  (추가 예제)
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(const int x, const vector<vector<int>> &graph, vector<int> &check, int c)
{
    check[x] = c;

    for (int i = 0; i < graph[x].size(); ++i)
    {
        int nextNode = graph[x][i];
        
        if (check[nextNode] == 0)
        {
            dfs(nextNode, graph, check, 3 - c);
        }
    
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int theNumberOfTestCases;
    cin >> theNumberOfTestCases;

    while (theNumberOfTestCases-- > 0)
    {
        int node, edge;
        cin >> node >> edge;

        vector<vector<int>> graph(node + 1);
        vector<int> check(node + 1, 0);

        //인접 리스트 생성
        for (int i = 0; i < edge; ++i)
        {
            int n1, n2;
            cin >> n1 >> n2;

            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        for (int i = 1; i <= node; ++i)
        {
            if (check[i] == 0)
                dfs(i, graph, check, 1);
        }

        //이분 그래프인지 판정
        //인접 리스트를 순회하면서 연결된 양끝의 색이 같으면 -> 이분 그래프가 아니다
        bool isBipartiteGraph = true;
        for (int i = 1; i <= node; ++i)
        {
            for (size_t j = 0; j < graph[i].size(); ++j)
            {
                int nextNode = graph[i][j];
                if (check[i] == check[nextNode])
                {               
                    isBipartiteGraph = false;
                }
            }
        }

        if (isBipartiteGraph)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

    }

    return 0;
}