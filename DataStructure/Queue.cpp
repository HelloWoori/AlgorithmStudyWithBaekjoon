/*
큐
https://www.acmicpc.net/problem/10845
*/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    deque<int> q;
    int cnt = 0;
    string cmd;

    cin >> cnt;
    while (cnt-- > 0)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int n = 0;
            cin >> n;
            q.push_back(n);
        }
        else if (cmd == "pop")
        {
            if (q.empty() == false)
            {
                cout << q.front() << '\n';
                q.pop_front();
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (q.empty() == false)
                cout << "0" << '\n';
            else
                cout << "1" << '\n';
        }
        else if (cmd == "front")
        {
            if (q.empty() == false)
                cout << q.front() << '\n';
            else
                cout << "-1" << '\n';
        }
        else if (cmd == "back")
        {
            if (q.empty() == false)
                cout << q.back() << '\n';
            else
                cout << "-1" << '\n';
        }
    }

    return 0;
}