/*
순열 사이클
https://www.acmicpc.net/problem/10451
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(const int x, const vector<vector<int>> &graph, vector<int> &check)
{
    check[x] = 1;

    for (size_t i = 0; i < graph[x].size(); ++i)
    {
        int next = graph[x][i];

        if (check[next] == 0)
        {
            check[next] = 1;
            dfs(next, graph, check);
        }
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int theNumOfTestCases;
    cin >> theNumOfTestCases;

    while (theNumOfTestCases-- > 0)
    {
        int size;
        cin >> size;

        vector<vector<int>> graph(size + 1);
        vector<int> check(size + 1);

        int num = 0;
        int input;
        for(int i = size; i > 0; --i)
        {
            num++;
            cin >> input;
            //연결리스트 생성
            graph[num].push_back(input);
        }

        //연결요소의 개수
        int componets = 0;
        for (int i = 1; i <= size; ++i)
        {
            if (check[i] == 0)
            {
                componets++;
                dfs(i, graph, check);
            }
        }

        cout << componets << '\n';
    
    }

    return 0;
}