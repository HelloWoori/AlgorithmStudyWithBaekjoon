/*
트리의 부모 찾기
https://www.acmicpc.net/problem/11725
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n(0);
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> check (n + 1, 0);
    vector<int> parent(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    queue<int> q;
    q.push(1);
    check[1] = 1;
    parent[1] = 0;

    while (false == q.empty())
    {
        int now = q.front();
        q.pop();

        for (const auto next : tree[now])
        {
            if (check[next] == 0)
            {
                check[next] = 1;
                parent[next] = now;
                q.push(next);
            }
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}