/*
트리의 지름
https://www.acmicpc.net/problem/1167
- https://www.acmicpc.net/board/view/584 (추가예제)
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
        //cout << "탐색순서: " << from << ' ';
        q.pop();

        for (size_t i = 0; i < tree[from].size(); ++i)
        {
            Edge to = tree[from][i];
            if (FALSE == check[to.val])
            {
                distance[to.val] = distance[from] + to.cost;
                check[to.val] = TRUE;
                q.push(to.val);
            }

        }
    }
    //cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int theNumOfNodes(0);
    cin >> theNumOfNodes;

    vector<vector<Edge>> tree(theNumOfNodes + 1);
    vector<int> check(theNumOfNodes + 1, FALSE);
    vector<int> distance(theNumOfNodes + 1, 0);

    for(int i = 0; i < theNumOfNodes; ++i)
    {
        int node(0);
        cin >> node;
        while (true)
        {
            int input1(0);
            cin >> input1;
            
            if (input1 == -1) break;

            int input2(0);
            cin >> input2;

            tree[node].push_back(Edge(input1, input2));
        }
    }

    //for debug
    //cout << "tree" << endl;
    //for (int from = 1; from <= theNumOfNodes; ++from)
    //{
    //    cout << from << ": ";
    //    for (const auto& to : tree[from])
    //    {
    //        cout << to.val << "(" << to.cost << ")" << ' ';
    //    }
    //    cout << '\n';
    //}

    /*첫번째 bfs*/
    bfs(1, tree, check, distance);

    //가장 먼 노드를 찾는다. 1로 임의 지정한 것을 루프돌며 갱신
    int farNode = 1; //임시 지정
    for (int i = 2; i <= theNumOfNodes; ++i) //어짜피 1은 루트라 거리가 0이므로 재낌!!
    {
        if (distance[i] > distance[farNode])
        {
            farNode = i;
        }
    }

    //for debug
    //cout << "farNode: " << farNode << '\n';

    /*두번째 bfs*/
    //다시 탐색해야하므로 check, distance 초기화
    check.clear();
    distance.clear();
    check.resize(theNumOfNodes + 1, FALSE);
    distance.resize(theNumOfNodes + 1, 0);

    //가장 먼 노드에서 다시 bfs 시작, 이때 구해진 가장 긴 거리가 트리의 지름
    bfs(farNode, tree, check, distance);
    int result = distance[1]; //임시 지정
    for (int i = 2; i <= theNumOfNodes; ++i)
    {
        if (result < distance[i])
            result = distance[i];
    }
    
    cout << result << '\n';

    return 0;
}