/*
조세퍼스 문제
https://www.acmicpc.net/problem/1158
*/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    deque<int> q, result;
    
    int N = 0, M = 0;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i)
    {
        q.push_back(i); // 1 ~ N까지 숫자 들어감
    }

    while (q.empty() == false)
    {
        int m = M - 1;
        while (m-- > 0)
        {
            q.push_back(q.front());
            q.pop_front();
        }
        result.push_back(q.front());
        q.pop_front();
    }

    cout << "<";
    for (auto it = result.begin(); it != result.end() - 1; ++it)
    {
        cout << *it << ", ";
    }
    cout << result.back() << ">" << '\n';

    return 0;
}