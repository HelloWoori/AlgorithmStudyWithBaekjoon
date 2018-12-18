
/*
트리의 지름
https://www.acmicpc.net/problem/1967
*/
#include <iostream>
#include <vector>
#include <queue>
#define FALSE 0
#define TRUE 1
using namespace std;

struct Edge
{
    int val;
    int cost;

    Edge() : val(0), cost(0) {}
    Edge(int _val, int _cost) : val(_val), cost(_cost) {}
};

void bfs(const int start,
         const vector<vector<Edge>>& tree,
               vector<int>& check,
               vector<int>& distance)
{
    queue<int> q;
    check[start] = TRUE;
    q.push(start);

    while (false == q.empty())
    {
        int from = q.front();
        q.pop();
        for (size_t i = 0; i < tree[from].size(); ++i)
        {
            Edge to = tree[from][i];
            if (false == check[to.val])
            {
                distance[to.val] = distance[from] + to.cost;
                check[to.val] = TRUE;
                q.push(to.val);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfNodes(0);
    cin >> theNumOfNodes;
    
    vector<vector<Edge>> tree(theNumOfNodes + 1);
    vector<int> check(theNumOfNodes + 1, FALSE);
    vector<int> distance(theNumOfNodes + 1, 0);

    for (int i = 0; i < theNumOfNodes - 1; ++i)
    {
        int parent(0), child(0), cost(0);
        cin >> parent >> child >> cost;

        //그래프는 사이클이 없는 무방향 그래프 이므로!!
        tree[parent].push_back(Edge(child, cost));
        tree[child].push_back(Edge(parent, cost));
    }

    //for debug
    //for (int i = 1; i <= theNumOfNodes; ++i)
    //{
    //    cout << i << ": ";
    //    for (const auto& t : tree[i])
    //    {
    //        cout << t.val << "(" << t.cost << ")" << ' ';
    //    }
    //    cout << '\n';
    //}

    //루트 노드에서 가장 먼 노드 구하기
    bfs(1, tree, check, distance);
    int farNode = 1;
    for (int i = 2; i <= theNumOfNodes; ++i)
    {
        if (distance[farNode] < distance[i])
            farNode = i;
    }

    //cout << "farNode: " << farNode << '\n';

    //가장 먼 노드에서 다시 탐색 시작
    check.clear();
    distance.clear();
    
    check.resize(theNumOfNodes + 1, FALSE);
    distance.resize(theNumOfNodes + 1, 0);

    bfs(farNode, tree, check, distance);
    int result = distance[1];
    for (int i = 2; i <= theNumOfNodes; ++i)
    {
        if (result < distance[i])
            result = distance[i];
    }

    cout << result << '\n';

    return 0;
}