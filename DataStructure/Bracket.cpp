/*
괄호
https://www.acmicpc.net/problem/9012
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    while (cnt-- > 0)
    {
        bool isVPS = true;
        vector<char> v;

        string cmd;
        cin >> cmd;

        for (auto c : cmd)
        {
            if (c == '(')
            {
                v.push_back(c);
            }
            else if (c == ')')
            {
                if (!v.empty())
                    v.pop_back();
                else
                {
                    isVPS = false;
                    cout << "NO" << '\n';
                    break;
                }
            }
        }

        if (isVPS)
        {
            if (v.empty())
                cout << "YES" << '\n';
            else
            {
                cout << "NO " << '\n';
            }
        }
    }
    return 0;
}